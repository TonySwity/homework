#include "temp_api.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void db_init(TemperatureDB *db) {
  db->data = NULL;
  db->size = 0;
  db->cap = 0;
}

void db_free(TemperatureDB *db) {
  free(db->data);
  db->data = NULL;
  db->size = db->cap = 0;
}

int db_reserve(TemperatureDB *db, size_t new_cap) {
  if (new_cap <= db->cap)
    return 0;
  TemperatureRecord *p = realloc(db->data, new_cap * sizeof(*p));
  if (!p)
    return -1;
  db->data = p;
  db->cap = new_cap;
  return 0;
}

int db_push(TemperatureDB *db, TemperatureRecord rec) {
  if (db->size == db->cap) {
    size_t nc = db->cap ? db->cap * 2 : 64;
    if (db_reserve(db, nc) < 0)
      return -1;
  }
  db->data[db->size++] = rec;
  return 0;
}

int db_erase(TemperatureDB *db, size_t index) {
  if (index >= db->size)
    return -1;
  for (size_t i = index + 1; i < db->size; ++i)
    db->data[i - 1] = db->data[i];
  db->size--;
  return 0;
}

static int cmp_rec(const void *a, const void *b) {
  const TemperatureRecord *x = a, *y = b;
  if (x->year != y->year)
    return x->year - y->year;
  if (x->month != y->month)
    return x->month - y->month;
  if (x->day != y->day)
    return x->day - y->day;
  if (x->hour != y->hour)
    return x->hour - y->hour;
  if (x->minute != y->minute)
    return x->minute - y->minute;
  return 0;
}
void db_sort(TemperatureDB *db) {
  qsort(db->data, db->size, sizeof(*db->data), cmp_rec);
}

void db_print(const TemperatureDB *db) {
  for (size_t i = 0; i < db->size; ++i) {
    const TemperatureRecord *r = &db->data[i];
    printf("%04d-%02d-%02d %02d:%02d = %d\n", r->year, r->month, r->day,
           r->hour, r->minute, r->temperature);
  }
}

int db_load_csv(TemperatureDB *db, const char *filename) {
  FILE *f = fopen(filename, "r");
  if (!f) {
    perror("open csv");
    return -1;
  }

  TemperatureRecord r;
  int count = 0;
  while (fscanf(f, "%d,%d,%d,%d,%d,%d", &r.year, &r.month, &r.day, &r.hour,
                &r.minute, &r.temperature) == 6) {
    if (db_push(db, r) < 0) {
      fclose(f);
      return -2;
    }
    ++count;
  }
  fclose(f);
  return count;
}

static int match_month(const TemperatureRecord *r, int y, int m) {
  return r->year == y && r->month == m;
}
static int match_year(const TemperatureRecord *r, int y) {
  return r->year == y;
}

double get_monthly_average(int year, int month, const TemperatureDB *db) {
  long sum = 0;
  int cnt = 0;
  for (size_t i = 0; i < db->size; ++i)
    if (match_month(&db->data[i], year, month)) {
      sum += db->data[i].temperature;
      ++cnt;
    }
  return cnt ? (double)sum / cnt : 0.0;
}
int get_monthly_min(int year, int month, const TemperatureDB *db) {
  int found = 0, mn = INT_MAX;
  for (size_t i = 0; i < db->size; ++i)
    if (match_month(&db->data[i], year, month)) {
      if (!found || db->data[i].temperature < mn)
        mn = db->data[i].temperature, found = 1;
    }
  return found ? mn : 0;
}
int get_monthly_max(int year, int month, const TemperatureDB *db) {
  int found = 0, mx = INT_MIN;
  for (size_t i = 0; i < db->size; ++i)
    if (match_month(&db->data[i], year, month)) {
      if (!found || db->data[i].temperature > mx)
        mx = db->data[i].temperature, found = 1;
    }
  return found ? mx : 0;
}
double get_yearly_average(int year, const TemperatureDB *db) {
  long sum = 0;
  int cnt = 0;
  for (size_t i = 0; i < db->size; ++i)
    if (match_year(&db->data[i], year)) {
      sum += db->data[i].temperature;
      ++cnt;
    }
  return cnt ? (double)sum / cnt : 0.0;
}
int get_yearly_min(int year, const TemperatureDB *db) {
  int found = 0, mn = INT_MAX;
  for (size_t i = 0; i < db->size; ++i)
    if (match_year(&db->data[i], year)) {
      if (!found || db->data[i].temperature < mn)
        mn = db->data[i].temperature, found = 1;
    }
  return found ? mn : 0;
}
int get_yearly_max(int year, const TemperatureDB *db) {
  int found = 0, mx = INT_MIN;
  for (size_t i = 0; i < db->size; ++i)
    if (match_year(&db->data[i], year)) {
      if (!found || db->data[i].temperature > mx)
        mx = db->data[i].temperature, found = 1;
    }
  return found ? mx : 0;
}

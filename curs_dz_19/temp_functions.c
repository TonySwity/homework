#include "temp_functions.h"
#include <limits.h>
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

static int db_reserve(TemperatureDB *db, size_t new_cap) {
  if (new_cap <= db->cap)
    return 0;
  TemperatureRecord *tmp = realloc(db->data, new_cap * sizeof(*tmp));
  if (!tmp)
    return -1;
  db->data = tmp;
  db->cap = new_cap;
  return 0;
}

int db_push(TemperatureDB *db, TemperatureRecord rec) {
  if (db->size == db->cap) {
    size_t new_cap = db->cap ? db->cap * 2 : 64;
    if (db_reserve(db, new_cap) < 0)
      return -1;
  }
  db->data[db->size++] = rec;
  return 0;
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
  for (size_t i = 0; i < db->size; i++)
    if (match_month(&db->data[i], year, month)) {
      sum += db->data[i].temperature;
      cnt++;
    }
  return cnt ? (double)sum / cnt : 0.0;
}
int get_monthly_min(int year, int month, const TemperatureDB *db) {
  int found = 0, mn = INT_MAX;
  for (size_t i = 0; i < db->size; i++)
    if (match_month(&db->data[i], year, month)) {
      if (!found || db->data[i].temperature < mn)
        mn = db->data[i].temperature;
      found = 1;
    }
  return found ? mn : 0;
}
int get_monthly_max(int year, int month, const TemperatureDB *db) {
  int found = 0, mx = INT_MIN;
  for (size_t i = 0; i < db->size; i++)
    if (match_month(&db->data[i], year, month)) {
      if (!found || db->data[i].temperature > mx)
        mx = db->data[i].temperature;
      found = 1;
    }
  return found ? mx : 0;
}

double get_yearly_average(int year, const TemperatureDB *db) {
  long sum = 0;
  int cnt = 0;
  for (size_t i = 0; i < db->size; i++)
    if (match_year(&db->data[i], year)) {
      sum += db->data[i].temperature;
      cnt++;
    }
  return cnt ? (double)sum / cnt : 0.0;
}
int get_yearly_min(int year, const TemperatureDB *db) {
  int found = 0, mn = INT_MAX;
  for (size_t i = 0; i < db->size; i++)
    if (match_year(&db->data[i], year)) {
      if (!found || db->data[i].temperature < mn)
        mn = db->data[i].temperature;
      found = 1;
    }
  return found ? mn : 0;
}
int get_yearly_max(int year, const TemperatureDB *db) {
  int found = 0, mx = INT_MIN;
  for (size_t i = 0; i < db->size; i++)
    if (match_year(&db->data[i], year)) {
      if (!found || db->data[i].temperature > mx)
        mx = db->data[i].temperature;
      found = 1;
    }
  return found ? mx : 0;
}

void print_help(void) {
  puts("Using: ./report -f <file.csv> [-m N]");
  puts("Keys:");
  puts("	-h	for help");
  puts("	-f	file.csv	load this file");
  puts("	-m N	statistics for  N (1..12) month");
}

int db_count_month(const TemperatureDB *db, int year, int month) {
  int n = 0;
  for (size_t i = 0; i < db->size; ++i)
    if (db->data[i].year == year && db->data[i].month == month)
      ++n;
  return n;
}

static int fpeekc(FILE *f) {
  int c = fgetc(f);
  if (c != EOF)
    ungetc(c, f);
  return c;
}

int db_load_csv(TemperatureDB *db, const char *filename, int *errors_out) {
  if (errors_out)
    *errors_out = 0;
  FILE *f = fopen(filename, "r");
  if (!f) {
    perror("Error open file");
    return -1;
  }

  int line = 0;
  TemperatureRecord r;
  for (;;) {
    int c = fpeekc(f);
    if (c == EOF)
      break;
    line++;
    int n = fscanf(f, "%d;%d;%d;%d;%d;%d", &r.year, &r.month, &r.day, &r.hour,
                   &r.minute, &r.temperature);
    if (n == 6) {
      db_push(db, r);
    } else {
      if (errors_out)
        (*errors_out)++;
      fprintf(stderr, "Error format in line %d\n", line);
      int ch;
      while ((ch = fgetc(f)) != '\n' && ch != EOF) {
      }
    }
  }
  fclose(f);
  return (int)db->size;
}

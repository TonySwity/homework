#include "temp_api.h"
#include <limits.h>

static int match_month(const TemperatureRecord *r, int year, int month) {
  return r->year == year && r->month == month;
}
static int match_year(const TemperatureRecord *r, int year) {
  return r->year == year;
}

double get_monthly_average(int year, int month, TemperatureRecord *records,
                           int size) {
  long sum = 0;
  int cnt = 0;
  for (int i = 0; i < size; ++i) {
    if (match_month(&records[i], year, month)) {
      sum += records[i].temperature;
      ++cnt;
    }
  }
  return cnt ? (double)sum / (double)cnt : 0.0; // если нет данных — 0.0
}

int get_monthly_min(int year, int month, TemperatureRecord *records, int size) {
  int found = 0;
  int mn = INT_MAX;
  for (int i = 0; i < size; ++i) {
    if (match_month(&records[i], year, month)) {
      if (!found || records[i].temperature < mn)
        mn = records[i].temperature;
      found = 1;
    }
  }
  return found ? mn : 0;
}

int get_monthly_max(int year, int month, TemperatureRecord *records, int size) {
  int found = 0;
  int mx = INT_MIN;
  for (int i = 0; i < size; ++i) {
    if (match_month(&records[i], year, month)) {
      if (!found || records[i].temperature > mx)
        mx = records[i].temperature;
      found = 1;
    }
  }
  return found ? mx : 0;
}

double get_yearly_average(int year, TemperatureRecord *records, int size) {
  long sum = 0;
  int cnt = 0;
  for (int i = 0; i < size; ++i) {
    if (match_year(&records[i], year)) {
      sum += records[i].temperature;
      ++cnt;
    }
  }
  return cnt ? (double)sum / (double)cnt : 0.0;
}

int get_yearly_min(int year, TemperatureRecord *records, int size) {
  int found = 0;
  int mn = INT_MAX;
  for (int i = 0; i < size; ++i) {
    if (match_year(&records[i], year)) {
      if (!found || records[i].temperature < mn)
        mn = records[i].temperature;
      found = 1;
    }
  }
  return found ? mn : 0;
}

int get_yearly_max(int year, TemperatureRecord *records, int size) {
  int found = 0;
  int mx = INT_MIN;
  for (int i = 0; i < size; ++i) {
    if (match_year(&records[i], year)) {
      if (!found || records[i].temperature > mx)
        mx = records[i].temperature;
      found = 1;
    }
  }
  return found ? mx : 0;
}

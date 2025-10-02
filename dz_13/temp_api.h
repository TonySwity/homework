#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdlib.h>

typedef struct {
  int year, month, day, hour, minute, temperature;
} TemperatureRecord;

typedef struct {
  TemperatureRecord *data;
  size_t size;
  size_t cap;
} TemperatureDB;

void db_init(TemperatureDB *db);
void db_free(TemperatureDB *db);
int db_reserve(TemperatureDB *db, size_t new_cap);
int db_push(TemperatureDB *db, TemperatureRecord rec);
int db_erase(TemperatureDB *db, size_t index);
void db_sort(TemperatureDB *db);
void db_print(const TemperatureDB *db);

int db_load_csv(TemperatureDB *db, const char *filename);

double get_monthly_average(int year, int month, const TemperatureDB *db);
int get_monthly_min(int year, int month, const TemperatureDB *db);
int get_monthly_max(int year, int month, const TemperatureDB *db);

double get_yearly_average(int year, const TemperatureDB *db);
int get_yearly_min(int year, const TemperatureDB *db);
int get_yearly_max(int year, const TemperatureDB *db);

#endif

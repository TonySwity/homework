#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdio.h>

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
int db_push(TemperatureDB *db, TemperatureRecord rec);
// int db_load_csv(TemperatureDB *db, const char *filename);
int db_load_csv(TemperatureDB *db, const char *filename, int *errors_out);
int db_count_month(const TemperatureDB *db, int year, int month);

double get_monthly_average(int year, int month, const TemperatureDB *db);
int get_monthly_min(int year, int month, const TemperatureDB *db);
int get_monthly_max(int year, int month, const TemperatureDB *db);

double get_yearly_average(int year, const TemperatureDB *db);
int get_yearly_min(int year, const TemperatureDB *db);
int get_yearly_max(int year, const TemperatureDB *db);

void print_help(void);

#endif

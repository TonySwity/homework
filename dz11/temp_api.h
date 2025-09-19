#ifndef TEMP_API_H
#define TEMP_API_H

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int temperature;
} TemperatureRecord;

double get_monthly_average(int year, int month, TemperatureRecord *records,
                           int size);
int get_monthly_min(int year, int month, TemperatureRecord *records, int size);
int get_monthly_max(int year, int month, TemperatureRecord *records, int size);

double get_yearly_average(int year, TemperatureRecord *records, int size);
int get_yearly_min(int year, TemperatureRecord *records, int size);
int get_yearly_max(int year, TemperatureRecord *records, int size);

#endif

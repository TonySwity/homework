#ifndef UTILS_H
#define UTILS_H

#include "temp_api.h"

int load_csv(const char *filename, TemperatureRecord *records, int max_size);
void print_records(TemperatureRecord *records, int size);
void add_record(TemperatureRecord *records, int *size, TemperatureRecord rec);
void delete_record(TemperatureRecord *records, int *size, int index);
void sort_records(TemperatureRecord *records, int size);

#endif

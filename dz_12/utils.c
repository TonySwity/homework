#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int load_csv(const char *filename, TemperatureRecord *records, int max_size) {
  FILE *f = fopen(filename, "r");
  if (!f) {
    perror("Ошибка открытия файла");
    return 0;
  }
  int count = 0;
  while (count < max_size &&
         fscanf(f, "%d,%d,%d,%d,%d,%d", &records[count].year,
                &records[count].month, &records[count].day,
                &records[count].hour, &records[count].minute,
                &records[count].temperature) == 6) {
    count++;
  }
  fclose(f);
  return count;
}

void print_records(TemperatureRecord *records, int size) {
  for (int i = 0; i < size; i++) {
    printf("%04d-%02d-%02d %02d:%02d = %d\n", records[i].year, records[i].month,
           records[i].day, records[i].hour, records[i].minute,
           records[i].temperature);
  }
}

void add_record(TemperatureRecord *records, int *size, TemperatureRecord rec) {
  records[*size] = rec;
  (*size)++;
}

void delete_record(TemperatureRecord *records, int *size, int index) {
  if (index < 0 || index >= *size)
    return;
  for (int i = index; i < *size - 1; i++) {
    records[i] = records[i + 1];
  }
  (*size)--;
}

void sort_records(TemperatureRecord *records, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (records[j].year > records[j + 1].year ||
          (records[j].year == records[j + 1].year &&
           records[j].month > records[j + 1].month)) {
        TemperatureRecord tmp = records[j];
        records[j] = records[j + 1];
        records[j + 1] = tmp;
      }
    }
  }
}

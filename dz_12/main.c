#include "temp_api.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

void print_help(void) {
  printf("Использование: ./main [ключи]\n");
  printf("Ключи:\n");
  printf("  -h            : показать справку\n");
  printf("  -f file.csv   : загрузить данные из файла\n");
  printf("  -m N          : вывести статистику только за месяц N (1-12)\n");
}

int main(int argc, char *argv[]) {
  TemperatureRecord records[MAX_RECORDS];
  int size = 0;
  int month_filter = 0;
  const char *filename = NULL;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      print_help();
      return 0;
    } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
      filename = argv[++i];
    } else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) {
      month_filter = atoi(argv[++i]);
    }
  }

  if (filename) {
    size = load_csv(filename, records, MAX_RECORDS);
  }

  if (size == 0) {
    printf("Нет данных!\n");
    return 1;
  }

  if (month_filter) {
    printf("=== Статистика за %d месяц ===\n", month_filter);
    printf("Средняя = %.2f\n",
           get_monthly_average(records[0].year, month_filter, records, size));
    printf("Мин = %d\n",
           get_monthly_min(records[0].year, month_filter, records, size));
    printf("Макс = %d\n",
           get_monthly_max(records[0].year, month_filter, records, size));
  } else {
    printf("=== Статистика за %d год ===\n", records[0].year);
    printf("Средняя = %.2f\n",
           get_yearly_average(records[0].year, records, size));
    printf("Мин = %d\n", get_yearly_min(records[0].year, records, size));
    printf("Макс = %d\n", get_yearly_max(records[0].year, records, size));
  }

  return 0;
}

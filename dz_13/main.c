#include "temp_api.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  const char *csv = NULL;
  int month = 0;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-h") == 0) {
      print_help();
      return 0;
    } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc)
      csv = argv[++i];
    else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc)
      month = atoi(argv[++i]);
  }

  TemperatureDB db;
  db_init(&db);

  if (csv) {
    if (db_load_csv(&db, csv) < 0) {
      fprintf(stderr, "Ошибка загрузки CSV\n");
      db_free(&db);
      return 1;
    }
  } else {
    /* демо-данные если файл не указан */
    db_push(&db, (TemperatureRecord){2025, 1, 15, 12, 30, -5});
    db_push(&db, (TemperatureRecord){2025, 1, 16, 14, 45, 3});
    db_push(&db, (TemperatureRecord){2025, 1, 20, 9, 15, -2});
    db_push(&db, (TemperatureRecord){2025, 2, 1, 10, 0, 5});
  }

  db_sort(&db);

  if (db.size == 0) {
    puts("Нет данных.");
    db_free(&db);
    return 0;
  }

  int year = db.data[0].year;

  if (month) {
    printf("=== Статистика: %04d/%02d ===\n", year, month);
    printf("Средняя: %.2f\n", get_monthly_average(year, month, &db));
    printf("Минимум: %d\n", get_monthly_min(year, month, &db));
    printf("Максимум: %d\n", get_monthly_max(year, month, &db));
  } else {
    printf("=== Статистика за %04d ===\n", year);
    printf("Средняя: %.2f\n", get_yearly_average(year, &db));
    printf("Минимум: %d\n", get_yearly_min(year, &db));
    printf("Максимум: %d\n", get_yearly_max(year, &db));
  }

  db_free(&db);
  return 0;
}

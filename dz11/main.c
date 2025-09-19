#include "temp_api.h"
#include <stdio.h>

#define MAX_RECORDS 1000

int main(void) {
  TemperatureRecord records[MAX_RECORDS];
  int size = 0;

  records[0] = (TemperatureRecord){2025, 1, 15, 12, 30, -5};
  records[1] = (TemperatureRecord){2025, 1, 16, 14, 45, 3};
  records[2] = (TemperatureRecord){2025, 1, 20, 9, 15, -2};
  size = 3;

  printf("=== Статистика за январь 2025 ===\n");
  printf("Среднемесячная температура: %.2f\n",
         get_monthly_average(2025, 1, records, size));
  printf("Мин. температура в месяце: %d\n",
         get_monthly_min(2025, 1, records, size));
  printf("Макс. температура в месяце: %d\n",
         get_monthly_max(2025, 1, records, size));

  printf("\n=== Статистика за 2025 год ===\n");
  printf("Среднегодовая температура: %.2f\n",
         get_yearly_average(2025, records, size));
  printf("Мин. температура в году: %d\n", get_yearly_min(2025, records, size));
  printf("Макс. температура в году: %d\n", get_yearly_max(2025, records, size));

  return 0;
}

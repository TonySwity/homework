#include <stdio.h>
void print_help(void) {
  puts("Температурная статистика");
  puts("Использование: ./main [-h] [-f file.csv] [-m N]");
  puts("  -h           Показать справку");
  puts("  -f file.csv  Загрузить данные из CSV (YYYY,MM,DD,hh,mm,temp)");
  puts("  -m N         Показать статистику только за месяц N (1..12)");
}

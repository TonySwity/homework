#include "temp_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  const char *filename = NULL;
  int month = 0;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      print_help();
      return 0;
    } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc)
      filename = argv[++i];
    else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc)
      month = atoi(argv[++i]);
  }
  if (!filename) {
    print_help();
    return 0;
  }

  TemperatureDB db;
  db_init(&db);
  int err = 0;
  int loaded = db_load_csv(&db, filename, &err);
  if (loaded <= 0) {
    db_free(&db);
    return 1;
  }

  int year = db.data[0].year;

  printf("#  Year	 Month NuValue	ErValue	"
         "MonthAvg MonthMax MonthMin\n");

  if (month) {
    int nu = db_count_month(&db, year, month);
    double avg = get_monthly_average(year, month, &db);
    int mx = get_monthly_max(year, month, &db);
    int mn = get_monthly_min(year, month, &db);

    printf("%2d %4d %6d %7d %7d %8.0f %8d %8d\n", 1, year, month, nu, 0, avg,
           mx, mn);
  } else {
    int row = 0;
    for (int m = 1; m <= 12; ++m) {
      int nu = db_count_month(&db, year, m);
      if (!nu)
        continue;
      double avg = get_monthly_average(year, m, &db);
      int mx = get_monthly_max(year, m, &db);
      int mn = get_monthly_min(year, m, &db);
      printf("%2d %4d %6d %7d %7d %8.0f %8d %8d\n", row++, year, m, nu, 0, avg,
             mx, mn);
    }
    printf("Year statistic: average is %.2f, max is %d, min is %d\n",
           get_yearly_average(year, &db), get_yearly_max(year, &db),
           get_yearly_min(year, &db));
    if (err > 0) {
      fprintf(stderr, "Skipped %d malformed lines.\n", err);
    }
  }

  db_free(&db);
  return 0;
}

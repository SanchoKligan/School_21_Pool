#include "database.h"

int main(void) {
  FILE *db = NULL;
  printf("Please choose one operation:\n1. SELECT\n2. INSERT\n3. UPDATE\n4. "
         "DELETE\n");
  int operation = 0;
  if (scanf("%d", &operation) == 1 && operation >= 1 && operation <= 9) {
    switch (operation) {
    case 1:
      printf(
          "Please choose a table:\n1. Modules\n2. Levels\n3. Status events\n");
      int db_file = 0;
      if (scanf("%d", &db_file) == 1 && db_file >= 1 && db_file <= 3) {
        switch (db_file) {
        case 1:
          select_modules(db);
          break;
        case 2:
          select_levels(db);
          break;
        case 3:
          select_status(db);
          break;
        }
      } else {
        printf("n/a");
      }
      break;
    case 2:
      printf(
          "Please choose a table:\n1. Modules\n2. Levels\n3. Status events\n");
      int db_file2 = 0;
      if (scanf("%d", &db_file2) == 1 && db_file2 >= 1 && db_file2 <= 3) {
        switch (db_file2) {
        case 1:
          insert_modules(db);
          break;
        case 2:
          insert_levels(db);
          break;
        case 3:
          insert_status(db);
          break;
        }
      } else {
        printf("n/a");
      }
      break;
    case 3:
      printf(
          "Please choose a table:\n1. Modules\n2. Levels\n3. Status events\n");
      int db_file3 = 0;
      if (scanf("%d", &db_file3) == 1 && db_file3 >= 1 && db_file3 <= 3) {
        switch (db_file3) {
        case 1:
          update_modules(db);
          break;
        case 2:
          update_levels(db);
          break;
        case 3:
          update_status(db);
          break;
        }
      } else {
        printf("n/a");
      }
      break;
    case 4:
      printf(
          "Please choose a table:\n1. Modules\n2. Levels\n3. Status events\n");
      int db_file4 = 0;
      if (scanf("%d", &db_file4) == 1 && db_file4 >= 1 && db_file4 <= 3) {
        switch (db_file4) {
        case 1:
          delete_modules(db);
          break;
        case 2:
          delete_levels(db);
          break;
        case 3:
          delete_status(db);
          break;
        }
      } else {
        printf("n/a");
      }
      break;
    }
  } else {
    printf("n/a");
  }
  return 0;
}
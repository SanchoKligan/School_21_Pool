#include "database.h"

void select_levels(FILE *db) {
  db = fopen("../materials/master_levels.db", "rb");
  int count = get_size(db) / sizeof(level);
  int number = 0;
  printf("Insert the number of records or 0 to output all of them: ");
  if (scanf("%d", &number) == 1 && number <= count && number >= 0) {
    if (number == 0) {
      number = count;
    }
    for (int i = 0; i < number; i++) {
      select(db, i, 2);
    }
  } else {
    printf("n/a");
  }
  fclose(db);
}

void insert_levels(FILE *db) {
  db = fopen("../materials/master_levels.db", "r+b");
  int count = get_size(db) / sizeof(level);
  printf("Insert data to add: ");
  level record;
  scanf("%d %d %d", &record.level_number, &record.cells_count,
        &record.protection_flag);
  insert(db, 2, &record, count);
  fclose(db);
}

void update_levels(FILE *db) {
  db = fopen("../materials/master_levels.db", "r+b");
  int count = get_size(db) / sizeof(level), id = 0;
  printf("Insert id to change: ");
  if (scanf("%d", &id) == 1 && id >= 0 && id <= count - 1) {
    printf("Insert data to add: ");
    level record;
    scanf("%d %d %d", &record.level_number, &record.cells_count,
          &record.protection_flag);
    update(db, 2, &record, id, count);
  }
  fclose(db);
}

void delete_levels(FILE *db) {
  db = fopen("../materials/master_levels.db", "r");
  int count = get_size(db) / sizeof(level), id = 0;
  printf("Insert id to delete: ");
  if (scanf("%d", &id) == 1 && id >= 0 && id <= count - 1) {
    delete (db, 2, id, count);
  }
  fclose(db);
}
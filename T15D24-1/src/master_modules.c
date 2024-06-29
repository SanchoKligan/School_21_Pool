#include "database.h"

void select_modules(FILE *db) {
  db = fopen("../materials/master_modules.db", "rb");
  int count = get_size(db) / sizeof(module);
  int number = 0;
  printf("Insert the number of records or 0 to output all of them: ");
  if (scanf("%d", &number) == 1 && number <= count && number >= 0) {
    if (number == 0) {
      number = count;
    }
    for (int i = 0; i < number; i++) {
      select(db, i, 1);
    }
  } else {
    printf("n/a");
  }
  fclose(db);
}

void insert_modules(FILE *db) {
  db = fopen("../materials/master_modules.db", "r+b");
  int count = get_size(db) / sizeof(module);
  printf("Insert data to add: ");
  module record;
  scanf("%d %29s %d %d %d", &record.module_id, record.module_name,
        &record.level_number, &record.cell_number, &record.delete_flag);
  insert(db, 1, &record, count);
  fclose(db);
}

void update_modules(FILE *db) {
  db = fopen("../materials/master_modules.db", "r+b");
  int count = get_size(db) / sizeof(module), id = 0;
  printf("Insert id to change: ");
  if (scanf("%d", &id) == 1 && id >= 0 && id <= count - 1) {
    printf("Insert data to add: ");
    module record;
    scanf("%d %29s %d %d %d", &record.module_id, record.module_name,
          &record.level_number, &record.cell_number, &record.delete_flag);
    update(db, 1, &record, id, count);
  }
  fclose(db);
}

void delete_modules(FILE *db) {
  db = fopen("../materials/master_modules.db", "r");
  int count = get_size(db) / sizeof(module), id = 0;
  printf("Insert id to delete: ");
  if (scanf("%d", &id) == 1 && id >= 0 && id <= count - 1) {
    delete (db, 1, id, count);
  }
  fclose(db);
}
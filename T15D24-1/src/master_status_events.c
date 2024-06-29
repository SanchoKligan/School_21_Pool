#include "database.h"

void select_status(FILE *db) {
  db = fopen("../materials/master_status_events.db", "rb");
  int count = get_size(db) / sizeof(status_event);
  int number = 0;
  printf("Insert the number of records or 0 to output all of them: ");
  if (scanf("%d", &number) == 1 && number <= count && number >= 0) {
    if (number == 0) {
      number = count;
    }
    for (int i = 0; i < number; i++) {
      select(db, i, 3);
    }
  } else {
    printf("n/a");
  }
  fclose(db);
}

void insert_status(FILE *db) {
  db = fopen("../materials/master_status_events.db", "r+b");
  int count = get_size(db) / sizeof(status_event);
  printf("Insert data to add: ");
  status_event record;
  scanf("%d %d %d %10s %8s", &record.event_id, &record.module_id,
        &record.new_module_status, record.status_date_change,
        record.status_time_change);
  insert(db, 3, &record, count);
  fclose(db);
}

void update_status(FILE *db) {
  db = fopen("../materials/master_status_events.db", "r+b");
  int count = get_size(db) / sizeof(status_event), id = 0;
  printf("Insert id to change: ");
  if (scanf("%d", &id) == 1 && id >= 0 && id <= count - 1) {
    printf("Insert data to add: ");
    status_event record;
    scanf("%d %d %d %10s %8s", &record.event_id, &record.module_id,
          &record.new_module_status, record.status_date_change,
          record.status_time_change);
    update(db, 3, &record, id, count);
  }
  fclose(db);
}

void delete_status(FILE *db) {
  db = fopen("../materials/master_status_events.db", "r");
  int count = get_size(db) / sizeof(status_event), id = 0;
  printf("Insert id to delete: ");
  if (scanf("%d", &id) == 1 && id >= 0 && id <= count - 1) {
    delete (db, 3, id, count);
  }
  fclose(db);
}
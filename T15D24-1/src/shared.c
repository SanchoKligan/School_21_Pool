#include "database.h"

void select(FILE *db, int id, int table) {
  switch (table) {
  case 1:
    module record1 = read_from_modules(db, id);
    printf("%d %s %d %d %d\n", record1.module_id, record1.module_name,
           record1.level_number, record1.cell_number, record1.delete_flag);
    break;
  case 2:
    level record2 = read_from_levels(db, id);
    printf("%d %d %d\n", record2.level_number, record2.cells_count,
           record2.protection_flag);
    break;
  case 3:
    status_event record3 = read_from_status(db, id);
    printf("%d %d %d %s %s\n", record3.event_id, record3.module_id,
           record3.new_module_status, record3.status_date_change,
           record3.status_time_change);
    break;
  }
}

void insert(FILE *db, int table, void *record, int id) {
  switch (table) {
  case 1:
    module *record1 = (module *)record;
    write_in_modules(db, record1, id);
    for (int i = 0; i < id + 1; i++) {
      select(db, i, table);
    }
    break;
  case 2:
    level *record2 = (level *)record;
    write_in_levels(db, record2, id);
    for (int i = 0; i < id + 1; i++) {
      select(db, i, table);
    }
    break;
  case 3:
    status_event *record3 = (status_event *)record;
    write_in_status(db, record3, id);
    for (int i = 0; i < id + 1; i++) {
      select(db, i, table);
    }
    break;
  }
}

void update(FILE *db, int table, void *record, int id, int count) {
  switch (table) {
  case 1:
    module *record1 = (module *)record;
    write_in_modules(db, record1, id);
    for (int i = 0; i < count; i++) {
      select(db, i, table);
    }
    break;
  case 2:
    level *record2 = (level *)record;
    write_in_levels(db, record2, id);
    for (int i = 0; i < count; i++) {
      select(db, i, table);
    }
    break;
  case 3:
    status_event *record3 = (status_event *)record;
    write_in_status(db, record3, id);
    for (int i = 0; i < count; i++) {
      select(db, i, table);
    }
    break;
  }
}

void delete (FILE *db, int table, int id, int count) {
  switch (table) {
  case 1: {
    int new_count = 0;
    FILE *temp = tmpfile();
    module record;
    for (int i = 0; i < id; i++) {
      record = read_from_modules(db, i);
      write_in_modules(temp, &record, i);
      new_count++;
    }
    for (int i = id + 1; i < count; i++) {
      record = read_from_modules(db, i);
      write_in_modules(temp, &record, new_count);
      new_count++;
    }
    fclose(db);
    db = fopen("../materials/master_modules.db", "w+b");
    for (int i = 0; i < new_count; i++) {
      record = read_from_modules(temp, i);
      write_in_modules(db, &record, i);
    }
    for (int i = 0; i < new_count; i++) {
      select(db, i, table);
    }
    fclose(temp);
    break;
  }
  case 2: {
    int new_count = 0;
    FILE *temp = tmpfile();
    level record2;
    for (int i = 0; i < id; i++) {
      record2 = read_from_levels(db, i);
      write_in_levels(temp, &record2, i);
      new_count++;
    }
    for (int i = id + 1; i < count; i++) {
      record2 = read_from_levels(db, i);
      write_in_levels(temp, &record2, new_count);
      new_count++;
    }
    fclose(db);
    db = fopen("../materials/master_levels.db", "w+b");
    for (int i = 0; i < new_count; i++) {
      record2 = read_from_levels(temp, i);
      write_in_levels(db, &record2, i);
    }
    for (int i = 0; i < new_count; i++) {
      select(db, i, table);
    }
    fclose(temp);
    break;
  }
  case 3: {
    int new_count = 0;
    FILE *temp = tmpfile();
    status_event record3;
    for (int i = 0; i < id; i++) {
      record3 = read_from_status(db, i);
      write_in_status(temp, &record3, i);
      new_count++;
    }
    for (int i = id + 1; i < count; i++) {
      record3 = read_from_status(db, i);
      write_in_status(temp, &record3, new_count);
      new_count++;
    }
    fclose(db);
    db = fopen("../materials/master_status_events.db", "w+b");
    for (int i = 0; i < new_count; i++) {
      record3 = read_from_status(temp, i);
      write_in_status(db, &record3, i);
    }
    for (int i = 0; i < new_count; i++) {
      select(db, i, table);
    }
    fclose(temp);
    break;
  }
  }
}

int get_size(FILE *db) {
  int size = 0;
  fseek(db, 0, SEEK_END);
  size = ftell(db);
  rewind(db);
  return size;
}

module read_from_modules(FILE *file, int index) {
  int offset = index * sizeof(module);
  fseek(file, offset, SEEK_SET);
  module record;
  fread(&record, sizeof(module), 1, file);
  rewind(file);
  return record;
}

level read_from_levels(FILE *file, int index) {
  int offset = index * sizeof(level);
  fseek(file, offset, SEEK_SET);
  level record;
  fread(&record, sizeof(level), 1, file);
  rewind(file);
  return record;
}
status_event read_from_status(FILE *file, int index) {
  int offset = index * sizeof(status_event);
  fseek(file, offset, SEEK_SET);
  status_event record;
  fread(&record, sizeof(status_event), 1, file);
  rewind(file);
  return record;
}

void write_in_modules(FILE *file, const module *record, int index) {
  int offset = index * sizeof(module);
  fseek(file, offset, SEEK_SET);
  fwrite(record, sizeof(module), 1, file);
  fflush(file);
  rewind(file);
}

void write_in_levels(FILE *file, const level *record, int index) {
  int offset = index * sizeof(level);
  fseek(file, offset, SEEK_SET);
  fwrite(record, sizeof(level), 1, file);
  fflush(file);
  rewind(file);
}

void write_in_status(FILE *file, const status_event *record, int index) {
  int offset = index * sizeof(status_event);
  fseek(file, offset, SEEK_SET);
  fwrite(record, sizeof(status_event), 1, file);
  fflush(file);
  rewind(file);
}
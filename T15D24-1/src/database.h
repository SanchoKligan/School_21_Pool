#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>

typedef struct module {
  int module_id;
  char module_name[30];
  int level_number;
  int cell_number;
  int delete_flag;
} module;

typedef struct level {
  int level_number;
  int cells_count;
  int protection_flag;
} level;

typedef struct status_event {
  int event_id;
  int module_id;
  int new_module_status;
  char status_date_change[11];
  char status_time_change[9];
} status_event;

void select(FILE *db, int id, int table);
void delete (FILE *db, int table, int id, int count);
void insert(FILE *db, int table, void *record, int id);
void update(FILE *db, int table, void *record, int id, int count);
int get_size(FILE *db);

void select_modules(FILE *db);
void insert_modules(FILE *db);
void update_modules(FILE *db);
void delete_modules(FILE *db);
module read_from_modules(FILE *file, int index);
void write_in_modules(FILE *file, const module *record, int index);

void select_levels(FILE *db);
void insert_levels(FILE *db);
void update_levels(FILE *db);
void delete_levels(FILE *db);
level read_from_levels(FILE *file, int index);
void write_in_levels(FILE *file, const level *record, int index);

void select_status(FILE *db);
void insert_status(FILE *db);
void update_status(FILE *db);
void delete_status(FILE *db);
status_event read_from_status(FILE *file, int index);
void write_in_status(FILE *file, const status_event *record, int index);

#endif
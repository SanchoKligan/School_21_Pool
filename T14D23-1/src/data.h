#ifndef DATA_H
#define DATA_H

#include <stdio.h>

typedef struct data {
    int year, month, day;
    int hour, minute, second;
    int status, code;
} data;

data read_from_file(FILE *file, int index);
void write_in_file(FILE *file, const data *record, int index);
void swap(FILE *file, int record1, int record2);
int get_size(FILE *file);
int get_records_count(FILE *file);
void output_data(FILE *file, int count);
void sort(FILE *file, int count);
int compare_records(data record1, data record2);
void data_to_record(FILE *file, int count);
int search(FILE *file, int day, int month, int year, int direct);
void clear_state(FILE *file, int index1, int index2, int count, char filepath[]);

#endif
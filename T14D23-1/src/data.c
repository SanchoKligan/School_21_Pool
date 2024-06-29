#include "data.h"

data read_from_file(FILE *file, int index) {
    int offset = index * sizeof(data);
    fseek(file, offset, SEEK_SET);
    data record;
    fread(&record, sizeof(data), 1, file);
    rewind(file);
    return record;
}

int get_size(FILE *file) {
    int size = 0;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    return size;
}

int get_records_count(FILE *file) { return get_size(file) / sizeof(data); }

void output_data(FILE *file, int count) {
    for (int i = 0; i < count; i++) {
        data record = read_from_file(file, i);
        printf("%d %d %d %d %d %d %d %d\n", record.year, record.month, record.day, record.hour, record.minute,
               record.second, record.status, record.code);
    }
}

void sort(FILE *file, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            swap(file, j, j + 1);
        }
    }
    output_data(file, count);
}

int compare_records(data record1, data record2) {
    _Bool flag = 0;
    int res = 0;
    if (record1.year > record2.year) {
        res = 1;
        flag = 1;
    } else if (record1.year < record2.year) {
        flag = 1;
    }
    if (!flag && record1.month > record2.month) {
        res = 1;
        flag = 1;
    } else if (!flag && record1.month < record2.month) {
        flag = 1;
    }
    if (!flag && record1.day > record2.day) {
        res = 1;
        flag = 1;
    } else if (!flag && record1.day < record2.day) {
        flag = 1;
    }
    if (!flag && record1.hour > record2.hour) {
        res = 1;
        flag = 1;
    } else if (!flag && record1.hour < record2.hour) {
        flag = 1;
    }
    if (!flag && record1.minute > record2.minute) {
        res = 1;
        flag = 1;
    } else if (!flag && record1.minute < record2.minute) {
        flag = 1;
    }
    if (!flag && record1.second > record2.second) {
        res = 1;
        flag = 1;
    } else if (record1.second < record2.second) {
        flag = 1;
    }
    return res;
}

void swap(FILE *file, int record1_index, int record2_index) {
    data record1 = read_from_file(file, record1_index);
    data record2 = read_from_file(file, record2_index);
    if (compare_records(record1, record2)) {
        write_in_file(file, &record1, record2_index);
        write_in_file(file, &record2, record1_index);
    }
}

void write_in_file(FILE *file, const data *record, int index) {
    int offset = index * sizeof(data);
    fseek(file, offset, SEEK_SET);
    fwrite(record, sizeof(data), 1, file);
    fflush(file);
    rewind(file);
}

void data_to_record(FILE *file, int count) {
    data record;
    if (scanf("%d %d %d %d %d %d %d %d", &record.year, &record.month, &record.day, &record.hour,
              &record.minute, &record.second, &record.status, &record.code) == 8) {
        write_in_file(file, &record, count);
        output_data(file, count + 1);
    } else {
        printf("n/a");
    }
}

int search(FILE *file, int day, int month, int year, int direct) {
    int count = get_records_count(file);
    _Bool flag = 0;
    int index = -1;
    if (direct == 0) {
        for (int i = 0; i < count && !flag; i++) {
            data record = read_from_file(file, i);
            if (record.year == year && record.month == month && record.day == day) {
                flag = 1;
                index = i;
            }
        }
    } else {
        for (int i = count - 1; i >= 0 && !flag; i--) {
            data record = read_from_file(file, i);
            if (record.year == year && record.month == month && record.day == day) {
                flag = 1;
                index = i;
            }
        }
    }
    return index;
}

void clear_state(FILE *file, int index1, int index2, int count, char filepath[]) {
    int new_count = 0;
    FILE *temp = tmpfile();
    data record;
    for (int i = 0; i < index1; i++) {
        record = read_from_file(file, i);
        write_in_file(temp, &record, i);
        new_count++;
    }
    for (int i = index2 + 1; i < count; i++) {
        record = read_from_file(file, i);
        write_in_file(temp, &record, new_count);
        new_count++;
    }
    fclose(file);
    file = fopen(filepath, "w+b");
    for (int i = 0; i < new_count; i++) {
        record = read_from_file(temp, i);
        write_in_file(file, &record, i);
    }
    output_data(file, new_count);
    fclose(temp);
}
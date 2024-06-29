#include "data.h"

int main(void) {
    char filepath[256];
    scanf("%s", filepath);
    FILE *file = fopen(filepath, "r+b");
    if (file != NULL && get_size(file) != 0) {
        int day1 = 0, month1 = 0, year1 = 0, day2 = 0, month2 = 0, year2 = 0;
        if (scanf("%d.%d.%d %d.%d.%d", &day1, &month1, &year1, &day2, &month2, &year2) == 6) {
            int count = get_records_count(file);
            sort(file, count);
            int index1 = search(file, day1, month1, year1, 0);
            int index2 = search(file, day2, month2, year2, 1);
            if (index1 <= index2 && index1 != -1 && index2 != -1) {
                clear_state(file, index1, index2, count, filepath);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    fclose(file);
    return 0;
}
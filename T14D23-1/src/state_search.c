#include "data.h"

int main(void) {
    char filepath[256];
    scanf("%s", filepath);
    FILE *file = fopen(filepath, "rb");
    if (file != NULL && get_size(file) != 0) {
        int day = 0, month = 0, year = 0;
        if (scanf("%d.%d.%d", &day, &month, &year) == 3) {
            int index = search(file, day, month, year, 0);
            if (index != -1) {
                data record = read_from_file(file, index);
                printf("%d", record.code);
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
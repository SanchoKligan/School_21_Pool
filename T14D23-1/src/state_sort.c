#include "data.h"

int main(void) {
    char filepath[256];
    scanf("%s", filepath);
    FILE *file = fopen(filepath, "r+b");
    if (file != NULL && get_size(file) != 0) {
        int n = 0;
        if (scanf("%d", &n) == 1) {
            int count = get_records_count(file);
            switch (n) {
                case 0:
                    output_data(file, count);
                    break;
                case 1:
                    sort(file, count);
                    break;
                case 2:
                    data_to_record(file, count);
                    break;
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
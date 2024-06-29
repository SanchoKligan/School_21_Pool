#include <stdio.h>

#include "documentation_module.h"
#include "print_module.h"

int main(void) {
#ifdef PM
    char (*ptr_print_char)(char) = print_char;
    print_log(ptr_print_char, Module_load_success_message);
#endif
// Output availability for each document....
#ifdef DM
    char docs[][100] = {Documents};
    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    for (int i = 0; i < Documents_count; i++) {
        if (availability_mask[i] == 0) {
            printf("%-15s : unavailable", docs[i]);
        } else {
            printf("%-15s : available", docs[i]);
        }
        if (i != Documents_count - 1) {
            printf("\n");
        }
    }
    free(availability_mask);
#endif
    return 0;
}

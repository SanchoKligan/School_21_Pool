#include "documentation_module.h"

int validate(char *data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int *check_available_documentation_module(int (*validate)(char *), int document_count, ...) {
    va_list arg;
    va_start(arg, document_count);
    int *docs = calloc(document_count, sizeof(int));
    for (int i = 0; i < document_count; i++) {
        docs[i] = validate(va_arg(arg, char *));
    }
    va_end(arg);
    return docs;
}
#include "stack.h"

#include <stdlib.h>
#include <string.h>

stack *init_stack(char name[], int priority, double value) {
    stack *top = malloc(sizeof(stack));
    top->priority = priority;
    top->value = value;
    strcpy(top->name, name);
    top->next = NULL;
    return top;
}

stack *push(stack *top, char name[], int priority, double value) {
    stack *new_top = malloc(sizeof(stack));
    strcpy(new_top->name, name);
    new_top->priority = priority;
    new_top->value = value;
    new_top->next = top;
    return new_top;
}

stack *pop(stack *top) {
    stack *new_top = NULL;
    if (top != NULL) {
        new_top = top->next;
        free(top);
    }
    return new_top;
}

void destroy_stack(stack *top) {
    stack *current = top->next;
    while (current != NULL) {
        free(top);
        top = current;
        current = top->next;
    }
    free(top);
}
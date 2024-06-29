#include "stack.h"

#include <stdio.h>

void push_test(struct stack **top);
void pop_test(struct stack **top);
void print_stack(struct stack *top);

int main(void) {
    struct stack *top = init(0);
    printf("---------\nPUSH_TEST\n---------\n");
    push_test(&top);
    printf("---------\nPOP_TEST\n---------\n");
    pop_test(&top);
    destroy(top);
    return 0;
}

void print_stack(struct stack *top) {
    struct stack *current = top;
    while (current != NULL) {
        printf("\t%d\n", current->data);
        current = current->next;
    }
}

void push_test(struct stack **top) {
    printf("Input:\n\t%d\n", 1);
    *top = push(*top, 1);
    printf("Output:\n");
    print_stack(*top);
    if ((*top)->data == 1) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
    printf("Input:\n\t%d\n", 2);
    *top = push(*top, 2);
    printf("Output:\n");
    print_stack(*top);
    if ((*top)->data == 2) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
    printf("Input:\n\t%d\n", 3);
    *top = push(*top, 3);
    printf("Output:\n");
    print_stack(*top);
    if ((*top)->data == 3) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
}

void pop_test(struct stack **top) {
    printf("Input:\n");
    print_stack(*top);
    *top = pop(*top);
    printf("Output:\n");
    print_stack(*top);
    if ((*top)->data == 2) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
    printf("Input:\n");
    print_stack(*top);
    *top = pop(*top);
    printf("Output:\n");
    print_stack(*top);
    if ((*top)->data == 1) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
    printf("Input:\n");
    print_stack(*top);
    *top = pop(*top);
    printf("Output:\n");
    print_stack(*top);
    if ((*top)->data == 0) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
}
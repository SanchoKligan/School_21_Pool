#ifndef STACK_H
#define STACK_H

typedef struct stack {
    char name[10];
    int priority;
    double value;
    struct stack *next;
} stack;

stack *init_stack(char name[], int priority, double value);  // инициализация стэка
stack *push(stack *top, char name[], int priority, double value);  // добавление элемента наверх стэка
stack *pop(stack *top);          // удаление верхушки стэка
void destroy_stack(stack *top);  // удаление стэка

#endif
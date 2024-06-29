#ifndef STACK_H
#define STACK_H

struct stack {
    int data;
    struct stack *next;
};

struct stack *init(int data);
struct stack *push(struct stack *top, int data);
struct stack *pop(struct stack *top);
void destroy(struct stack *top);

#endif
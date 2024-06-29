#include "compute.h"

#include <string.h>

double result(const queue *head, double value) {
    stack *top = init_stack(" ", 0, 0);
    const queue *p = head;
    double temp = 0.0;
    while (p != NULL) {
        if (strcmp(p->data, "+") == 0) {
            temp = top->value + top->next->value;
            top = push(pop(pop(top)), " ", 0, temp);
        } else if (strcmp(p->data, "-") == 0) {
            temp = top->next->value - top->value;
            top = push(pop(pop(top)), " ", 0, temp);
        } else if (strcmp(p->data, "*") == 0) {
            temp = top->value * top->next->value;
            top = push(pop(pop(top)), " ", 0, temp);
        } else if (strcmp(p->data, "/") == 0) {
            temp = top->next->value / top->value;
            top = push(pop(pop(top)), " ", 0, temp);
        } else if (strcmp(p->data, "sin") == 0) {
            temp = sin(top->value);
            top = push(pop(top), " ", 0, temp);
        } else if (strcmp(p->data, "cos") == 0) {
            temp = cos(top->value);
            top = push(pop(top), " ", 0, temp);
        } else if (strcmp(p->data, "tg") == 0) {
            temp = tan(top->value);
            top = push(pop(top), " ", 0, temp);
        } else if (strcmp(p->data, "ctg") == 0) {
            temp = 1.0 / tan(top->value);
            top = push(pop(top), " ", 0, temp);
        } else if (strcmp(p->data, "sqrt") == 0) {
            temp = sqrt(top->value);
            top = push(pop(top), " ", 0, temp);
        } else if (strcmp(p->data, "ln") == 0) {
            temp = log(top->value);
            top = push(pop(top), " ", 0, temp);
        } else if (strcmp(p->data, "~") == 0) {
            temp = top->value * -1;
            top = push(pop(top), " ", 0, temp);
        } else if (strcmp(p->data, "x") == 0) {
            top = push(top, " ", 0, value);
        } else {
            top = push(top, " ", 0, atof(p->data));
        }
        p = p->next;
    }
    temp = top->value;
    destroy_stack(top);
    return temp;
}
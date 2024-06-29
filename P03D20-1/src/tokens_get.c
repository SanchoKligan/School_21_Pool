#include "tokens_get.h"

#include <stdlib.h>
#include <string.h>

stack *pop_priority(stack *top, queue *head, int priority) {
    stack *p = top;
    while (p->priority >= priority) {
        push_back(head, p->name);
        p = pop(p);
    }
    return p;
}

char *get_string(char *p) {
    char *string = calloc(100, sizeof(char));
    char s[2];
    s[1] = '\0';
    _Bool flag = 0;
    while ((((int)(*p) >= 0x30 && (int)(*p) <= 0x39) || *p == '.') && *p != '\n') {
        flag = 1;
        s[0] = *p;
        strcat(string, s);
        p++;
    }
    while (((int)(*p) <= 0x30 || (int)(*p) >= 0x39) && *p != '\n' && *p != '+' && *p != '-' && *p != '*' &&
           *p != '/' && *p != '(' && *p != ')' && !flag) {
        s[0] = *p;
        strcat(string, s);
        p++;
    }
    return string;
}

stack *clear_stack(stack *top, queue *head, char stop[]) {
    stack *po = top;
    while (strcmp(po->name, stop) != 0) {
        push_back(head, po->name);
        po = pop(po);
    }
    po = pop(po);
    if (po != NULL && strcmp(stop, "(") == 0) {
        if (strcmp(po->name, "sin") == 0 || strcmp(po->name, "cos") == 0 || strcmp(po->name, "tg") == 0 ||
            strcmp(po->name, "ctg") == 0 || strcmp(po->name, "sqrt") == 0 || strcmp(po->name, "ln") == 0) {
            push_back(head, po->name);
            po = pop(po);
        }
    }
    return po;
}

queue *tokens_get(char string[]) {
    queue *head = init_queue(" ");
    stack *top = init_stack(" ", 0, 0);
    char *p = string;
    while (*p != '\n') {
        char *var = NULL;
        char str[2];
        str[0] = *p;
        str[1] = '\0';
        switch (*p) {
            case '+':
                top = push(pop_priority(top, head, 1), str, 1, 0);
                break;
            case '-':
                if (p - string == 0 || *(p - 1) == '(')
                    top = push(top, "~", 4, 0);
                else
                    top = push(pop_priority(top, head, 1), str, 1, 0);
                break;
            case '*':
            case '/':
                top = push(pop_priority(top, head, 2), str, 1, 0);
                break;
            case '(':
                top = push(top, str, 0, 0);
                break;
            case ')':
                top = clear_stack(top, head, "(");
                break;
            case ' ':
                break;
            default:
                var = get_string(p);
                if (strcmp(var, "sin") == 0 || strcmp(var, "cos") == 0 || strcmp(var, "tg") == 0 ||
                    strcmp(var, "ctg") == 0 || strcmp(var, "sqrt") == 0 || strcmp(var, "ln") == 0) {
                    top = push(top, var, 3, 0);
                } else if ((int)var[0] >= 0x30 && (int)var[0] <= 0x39)
                    push_back(head, var);
                else
                    push_back(head, "x");
                p += (strlen(var) - 1);
                free(var);
                var = NULL;
                break;
        }
        p++;
    }
    clear_stack(top, head, " ");
    return head;
}
#ifndef TG_H
#define TG_H

#include "queue.h"
#include "stack.h"

stack *pop_priority(stack *top, queue *head, int priority);  // сравнение приоритетов операций
char *get_string(char *p);  // считывание чисел и пременных (особенно многозначных)
stack *clear_stack(stack *top, queue *head,
                   char stop[]);  // удаление остатков из стека (либо до конца, либо до скобки)
queue *tokens_get(char string[]);  // преобразование в польскую нотацию

#endif
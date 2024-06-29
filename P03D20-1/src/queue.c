#include "queue.h"

#include <stdlib.h>
#include <string.h>

queue *init_queue(char data[]) {
    queue *head = malloc(sizeof(queue));
    strcpy(head->data, data);
    head->next = NULL;
    return head;
}

void push_back(queue *head, char data[]) {
    queue *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    queue *new_elem = malloc(sizeof(queue));
    p->next = new_elem;
    strcpy(new_elem->data, data);
    new_elem->next = NULL;
}

void destroy_queue(queue *head) {
    queue *current = head->next;
    while (current != NULL) {
        free(head);
        head = current;
        current = head->next;
    }
    free(head);
}
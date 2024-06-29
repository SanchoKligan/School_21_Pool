#include "list.h"

#include <stdlib.h>

struct node *init(const struct door *door) {
    struct node *p = malloc(sizeof(struct node));
    p->door = *door;
    p->next = NULL;
    return p;
}

struct node *add_door(struct node *elem, const struct door *door) {
    struct node *new_elem, *temp;
    new_elem = (struct node *)malloc(sizeof(struct node));
    temp = elem->next;
    elem->next = new_elem;
    new_elem->door = *door;
    new_elem->next = temp;
    return new_elem;
}

struct node *find_door(int door_id, struct node *root) {
    struct node *current = root, *res = NULL;
    _Bool flag = 0;
    while (current != NULL && !flag) {
        if (current->door.id == door_id) {
            flag = 1;
            res = current;
        }
        current = current->next;
    }
    return res;
}

struct node *remove_door(struct node *elem, struct node *root) {
    struct node *current = root;
    while (current->next != elem) {
        current = current->next;
    }
    current->next = elem->next;
    free(elem);
    return current;
}

void destroy(struct node *root) {
    struct node *current = root->next;
    while (current != NULL) {
        free(root);
        root = current;
        current = root->next;
    }
    free(root);
}
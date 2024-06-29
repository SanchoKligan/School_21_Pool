#include "list.h"

#include <stdio.h>

void add_door_test(struct node *root);
void remove_door_test(struct node *root);
void print_list(struct node *root);

int main(void) {
    struct door door = {0, 1};
    struct node *root = init(&door);
    printf("---------\nADD_TEST\n---------\n");
    add_door_test(root);
    printf("---------\nREMOVE_TEST\n---------\n");
    remove_door_test(root);
    destroy(root);
    return 0;
}

void print_list(struct node *root) {
    struct node *current = root;
    while (current != NULL) {
        printf("\t%d, %d\n", current->door.id, current->door.status);
        current = current->next;
    }
}

void add_door_test(struct node *root) {
    struct door door = {1, 0};
    printf("Input:\n\t%d, %d\n", door.id, door.status);
    struct node *p = add_door(root, &door);
    printf("Output:\n");
    print_list(root);
    if (find_door(door.id, root) != NULL) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
    door.id = 2;
    door.status = 1;
    printf("Input:\n\t%d, %d\n", door.id, door.status);
    add_door(p, &door);
    printf("Output:\n");
    print_list(root);
    if (find_door(door.id, root) != NULL) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
    door.id = 3;
    door.status = 0;
    printf("Input:\n\t%d, %d\n", door.id, door.status);
    add_door(root, &door);
    printf("Output:\n");
    print_list(root);
    if (find_door(door.id, root) != NULL) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
}

void remove_door_test(struct node *root) {
    struct node *p = find_door(2, root);
    printf("Input:\n\t%d, %d\n", p->door.id, p->door.status);
    p = remove_door(p, root);
    printf("Output:\n");
    print_list(root);
    if (find_door(2, root) == NULL) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
    p = find_door(3, root);
    printf("Input:\n\t%d, %d\n", p->door.id, p->door.status);
    p = remove_door(p, root);
    printf("Output:\n");
    print_list(root);
    if (find_door(3, root) == NULL) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
    p = find_door(1, root);
    printf("Input:\n\t%d, %d\n", p->door.id, p->door.status);
    remove_door(p, root);
    printf("Output:\n");
    print_list(root);
    if (find_door(1, root) == NULL) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
}
#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_btree {
    int item;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

void print_leaf(int item);
int compare(int a, int b);
t_btree *bstree_create_node(int item);
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));
void bstree_apply_infix(t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(t_btree *root, void (*applyf)(int));

#endif
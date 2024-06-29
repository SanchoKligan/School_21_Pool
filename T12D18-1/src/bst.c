#include "bst.h"

void print_leaf(int item) { printf("%d ", item); }

int compare(int a, int b) { return a < b ? 1 : 0; }

t_btree *bstree_create_node(int item) {
    t_btree *root = malloc(sizeof(t_btree));
    root->item = item;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    t_btree *new_root = root, *old_root;
    t_btree *tmp = malloc(sizeof(t_btree));
    tmp->item = item;
    while (new_root != NULL) {
        old_root = new_root;
        if (cmpf(item, new_root->item)) {
            new_root = new_root->left;
        } else {
            new_root = new_root->right;
        }
    }
    tmp->left = NULL;
    tmp->right = NULL;
    if (cmpf(item, old_root->item)) {
        old_root->left = tmp;
    } else {
        old_root->right = tmp;
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, applyf);
        applyf(root->item);
        bstree_apply_infix(root->right, applyf);
    }
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        applyf(root->item);
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    }
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_postfix(root->left, applyf);
        bstree_apply_postfix(root->right, applyf);
        applyf(root->item);
    }
}
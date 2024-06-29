#include "bst.h"

int main(void) {
    int (*cmpf)(int, int) = compare;
    printf("Input:\n\t4 2 3 5 1\n");
    t_btree *root = bstree_create_node(4);
    bstree_insert(root, 2, cmpf);
    bstree_insert(root, 3, cmpf);
    bstree_insert(root, 5, cmpf);
    bstree_insert(root, 1, cmpf);
    printf("Output:\n%20d\n%10d%20d\n%5d%10d\n", root->item, root->left->item, root->right->item,
           root->left->left->item, root->left->right->item);
    free(root->left->left);
    free(root->left->right);
    free(root->right);
    free(root->left);
    free(root);
    printf("\n\n");
    printf("Input:\n\t3 5 4 6 2\n");
    t_btree *root2 = bstree_create_node(3);
    bstree_insert(root2, 5, cmpf);
    bstree_insert(root2, 4, cmpf);
    bstree_insert(root2, 6, cmpf);
    bstree_insert(root2, 2, cmpf);
    printf("Output:\n%20d\n%10d%20d\n%25d%10d\n", root2->item, root2->left->item, root2->right->item,
           root2->right->left->item, root2->right->right->item);
    free(root2->right->left);
    free(root2->right->right);
    free(root2->right);
    free(root2->left);
    free(root2);
    return 0;
}
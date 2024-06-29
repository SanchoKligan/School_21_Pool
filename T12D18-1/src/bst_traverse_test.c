#include "bst.h"

int main(void) {
    int (*cmpf)(int, int) = compare;
    void (*applyf)(int) = print_leaf;
    t_btree *root = bstree_create_node(4);
    bstree_insert(root, 2, cmpf);
    bstree_insert(root, 3, cmpf);
    bstree_insert(root, 5, cmpf);
    bstree_insert(root, 1, cmpf);
    printf("Input:\n%20d\n%10d%20d\n%5d%10d\n", root->item, root->left->item, root->right->item,
           root->left->left->item, root->left->right->item);
    printf("Output (infix):\n\t");
    bstree_apply_infix(root, applyf);
    printf("\nOutput (prefix):\n\t");
    bstree_apply_prefix(root, applyf);
    printf("\nOutput (postfix):\n\t");
    bstree_apply_postfix(root, applyf);
    free(root->left->left);
    free(root->left->right);
    free(root->right);
    free(root->left);
    free(root);
    printf("\n\n");
    t_btree *root2 = bstree_create_node(3);
    bstree_insert(root2, 5, cmpf);
    bstree_insert(root2, 4, cmpf);
    bstree_insert(root2, 6, cmpf);
    bstree_insert(root2, 2, cmpf);
    printf("Input:\n%20d\n%10d%20d\n%25d%10d\n", root2->item, root2->left->item, root2->right->item,
           root2->right->left->item, root2->right->right->item);
    printf("Output (infix):\n\t");
    bstree_apply_infix(root2, applyf);
    printf("\nOutput (prefix):\n\t");
    bstree_apply_prefix(root2, applyf);
    printf("\nOutput (postfix):\n\t");
    bstree_apply_postfix(root2, applyf);
    free(root2->right->left);
    free(root2->right->right);
    free(root2->right);
    free(root2->left);
    free(root2);
    return 0;
}
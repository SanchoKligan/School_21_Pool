#include "bst.h"

int main(void) {
    printf("Input:\n\t%d\n", 4);
    t_btree *root1 = bstree_create_node(4);
    printf("Output:\n\t%d\n", root1->item);
    if (root1->item == 4) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
    printf("Input:\n\t%d\n", 3);
    t_btree *root2 = bstree_create_node(3);
    printf("Output:\n\t%d\n", root2->item);
    if (root2->item == 3) {
        printf("Result:\n\tSUCCESS\n\n");
    } else {
        printf("Result:\n\tFAIL\n\n");
    }
    free(root1);
    free(root2);
    return 0;
}
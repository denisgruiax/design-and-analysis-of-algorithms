#include <stdio.h>
#include "../interface/generalized-trees.h"

int main(int argumentCounter, char *arguments[])
{
    GeneralizedTree *tree = NULL;

    create_root(&tree, 1);

    add_son(tree, 1, 2);
    add_son(tree, 1, 3);
    add_son(tree, 1, 4);

    add_son(tree, 2, 5);
    add_son(tree, 2, 6);

    add_son(tree, 4, 7);
    add_son(tree, 4, 8);
    add_son(tree, 4, 9);

    preorder(tree);
    putchar('\n');

    inorder(tree);
    putchar('\n');

    putchar('\n');

    return 0;
}
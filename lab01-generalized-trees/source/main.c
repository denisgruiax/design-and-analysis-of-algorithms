#include <stdio.h>
#include "../interface/generalized-trees.h"

int main(int argumentCounter, char *arguments[])
{
    GeneralizedTree *tree = NULL;

    create_root(&tree, 1);

    add_son(tree, 1, 2);
    add_son(tree, 1, 3);
    add_son(tree, 1, 4);
    add_son(tree, 1, 99);
    add_son(tree, 1, 98);
    add_son(tree, 1, 97);
    add_son(tree, 1, 96);

    add_son(tree, 2, 5);
    add_son(tree, 2, 6);

    add_son(tree, 3, 5);
    add_son(tree, 3, 10);
    add_son(tree, 10, 11);
    add_son(tree, 11, 12);

    add_son(tree, 4, 7);
    add_son(tree, 4, 8);
    add_son(tree, 4, 9);

    printf("%i\n", depth_of_node(tree, 2));
    printf("%i\n", depth_of_node(tree, 12));
    printf("%i\n", depth_of_node(tree, 9));

    return 0;
}
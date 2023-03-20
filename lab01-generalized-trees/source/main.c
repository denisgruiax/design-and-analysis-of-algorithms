#include <stdio.h>
#include "../interface/generalized-trees.h"

int main(int argumentCounter, char *arguments[])
{
    GeneralizedTree *tree = NULL;

    create_root(&tree, 1);

    add_son(tree, 1, 2);
    add_son(tree, 1, 3);
    add_son(tree, 1, 4);
    add_son(tree, 1, 14);
    add_son(tree, 1, 15);

    add_son(tree, 2, 5);
    add_son(tree, 2, 6);
    add_son(tree, 2, 7);

    add_son(tree, 3, 8);
    add_son(tree, 3, 9);
    add_son(tree, 3, 10);
    add_son(tree, 3, 11);

    add_son(tree, 4, 12);
    add_son(tree, 4, 13);

    add_son(tree, 15, 16);

    add_son(tree, 16, 17);
    add_son(tree, 16, 18);

    add_son(tree, 17, 19);

    add_son(tree, 18, 20);

    add_son(tree, 20, 21);

    printf("%i\n", the_rightmost_brother(tree, 1));
    printf("%i\n", the_rightmost_brother(tree, 21));
    printf("%i\n", the_rightmost_brother(tree, 12));
    printf("%i\n", the_rightmost_brother(tree, 8));
    printf("%i\n", the_rightmost_brother(tree, 1013));

    return 0;
}
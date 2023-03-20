#include "../interface/ordered-binary-trees.h"

int main()
{
    printf("ordered binary trees\n");

    OrderedBinaryTree tree = NULL;
    add(&tree, 10);

    add(&tree, 5);
    add(&tree, 4);
    add(&tree, 7);
    add(&tree, 6);
    add(&tree, 8);

    add(&tree, 20);
    add(&tree, 19);
    add(&tree, 18);
    add(&tree, 21);
    add(&tree, 22);

    preorder(tree);
    puts("\n");
    
    printf("%i\n", smallest_node(tree));
    printf("%i\n", greatest_node(tree));

    return 0;
}
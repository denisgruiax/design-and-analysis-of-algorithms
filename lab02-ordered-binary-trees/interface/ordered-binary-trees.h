#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int boolean;

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} ;

typedef struct Node *OrderedBinaryTree;

void add(OrderedBinaryTree *root, int key);
OrderedBinaryTree initialize(OrderedBinaryTree *root);

boolean search(OrderedBinaryTree root, int key);

void suppress(OrderedBinaryTree *root, int key);

void preorder(OrderedBinaryTree tree);
void inorder(OrderedBinaryTree tree);
void postorder(OrderedBinaryTree tree);

int same_geometric_shape(OrderedBinaryTree tree, OrderedBinaryTree tree2);

int smallest_node(OrderedBinaryTree tree);
int greatest_node(OrderedBinaryTree tree);

int height(OrderedBinaryTree tree);
void display_on_levels(OrderedBinaryTree tree);

OrderedBinaryTree symmetric(OrderedBinaryTree tree);
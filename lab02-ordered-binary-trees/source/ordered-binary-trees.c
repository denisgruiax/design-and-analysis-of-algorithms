#include "../interface/ordered-binary-trees.h"

void static create(OrderedBinaryTree *root, int key)
{
    if (!(*root))
    {
        *root = (OrderedBinaryTree)malloc(sizeof(struct Node));
        (*root)->value = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
        printf("Root already exists!");
}

void add(OrderedBinaryTree *root, int key)
{
    if (!(*root))
    {
        create(root, key);
        return;
    }

    if (key < ((*root)->value))
        add(&(*root)->left, key);
    else
        add(&(*root)->right, key);
}

boolean search(OrderedBinaryTree root, int key)
{
    if (!root)
        return FALSE;

    if (key == root->value)
        return TRUE;

    if (key < root->value)
        search(root->left, key);
    else
        search(root->right, key);
}

OrderedBinaryTree initialize(OrderedBinaryTree *root)
{
    if (*root)
    {
        initialize(&(*root)->left);
        initialize(&(*root)->right);
        free(*root);
    }

    return NULL;
}

void suppress(OrderedBinaryTree *root, int key)
{
    if (!(*root))
        return;

    if (*root)
        if (key == (*root)->value)
            *root = initialize(&(*root));
        else if (key <= (*root)->value)
            suppress(&(*root)->left, key);
        else
            suppress(&(*root)->right, key);
}

void preorder(OrderedBinaryTree tree)
{
    if (tree)
    {
        printf("%i ", tree->value);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(OrderedBinaryTree tree)
{
    if (tree)
    {
        inorder(tree->left);
        printf("%i ", tree->value);
        inorder(tree->right);
    }
}

void postorder(OrderedBinaryTree tree)
{
    if (tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%i ", tree->value);
    }
}

int same_geometric_shape(OrderedBinaryTree tree, OrderedBinaryTree tree2)
{
    return 0;
}

int smallest_node(OrderedBinaryTree tree)
{
    if (!tree)
        return 0;

    if (!tree->left)
        return tree->value;

    smallest_node(tree->left);
}

int greatest_node(OrderedBinaryTree tree)
{
    if (!tree)
        return 0;

    if (!tree->right)
        return tree->value;

    greatest_node(tree->right);
}

void display_on_levels(OrderedBinaryTree tree)
{
    
}
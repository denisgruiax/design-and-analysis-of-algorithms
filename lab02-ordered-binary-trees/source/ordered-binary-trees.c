#include "../interface/ordered-binary-trees.h"

static int max(int value, int value2);
static void create(OrderedBinaryTree *root, int key);
static void display(OrderedBinaryTree tree, int h);
static int same_geometric_shape_recursive(OrderedBinaryTree tree, OrderedBinaryTree tree2);
static int height_recursive(OrderedBinaryTree tree);

static void create(OrderedBinaryTree *root, int key)
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

static void display(OrderedBinaryTree tree, int h)
{

    if (tree != NULL)
    {
        display(tree->left, h - 1);

        for (int i = 1; i <= h; i++)
            printf("%3s", " ");

        printf("%3d\n", tree->value);
        display(tree->right, h - 1);
    }
}

static int same_geometric_shape_recursive(OrderedBinaryTree tree, OrderedBinaryTree tree2)
{
    if (!tree && !tree2)
        return 1;

    if (tree && tree2)
        return (same_geometric_shape_recursive(tree->left, tree2->left) && same_geometric_shape_recursive(tree->right, tree2->right));

    return 0;
}

static int height_recursive(OrderedBinaryTree tree)
{
    int max_height = 0;

    if (tree)
    {
        if (tree->left)
            max_height = max(max_height, height_recursive(tree->left));

        if (tree->right)
            max_height = max(max_height, height_recursive(tree->right));

        max_height++;
    }

    return max_height;
}

static int max(int value, int value2)
{
    return value > value2 ? value : value2;
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
        return search(root->left, key);
    else
        return search(root->right, key);
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
    {
        if (key == (*root)->value)
            *root = initialize(&(*root));
        else if (key <= (*root)->value)
            suppress(&(*root)->left, key);
        else
            suppress(&(*root)->right, key);
    }
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
    return same_geometric_shape_recursive(tree, tree2);
}

int smallest_node(OrderedBinaryTree tree)
{
    if (!tree)
        return 0;

    if (!tree->left)
        return tree->value;

    return smallest_node(tree->left);
}

int greatest_node(OrderedBinaryTree tree)
{
    if (!tree)
        return 0;

    if (!tree->right)
        return tree->value;

    return greatest_node(tree->right);
}

int height(OrderedBinaryTree tree)
{
    return height_recursive(tree) - 1;
}

void display_on_levels(OrderedBinaryTree tree)
{
    display(tree, height(tree));
}

OrderedBinaryTree symmetric(OrderedBinaryTree tree)
{
    OrderedBinaryTree swapper = NULL;

    if (tree)
    {
        symmetric(tree->left);
        symmetric(tree->right);

        swapper = tree->left;
        tree->left = tree->right;
        tree->right = swapper;
    }

    return tree;
}
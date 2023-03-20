#include "../interface/generalized-trees.h"
#include <stdio.h>
#include <stdlib.h>

NodePointer node_pointer(NodePointer root, const int value)
{
    NodePointer root2 = NULL, father = NULL, index = NULL;
    
    father = root;

    if (father)
    {
        if (father->value == value)
            return father;

        for (index = father->first_son; index; index = index->right_brother)
        {
            if (index->value == value)
                return index;

            root2 = node_pointer(index, value);

            if (root2)
                return root2;
        }

        return NULL;
    }

    return NULL;
}

char line[40] = "";

void print_value(NodePointer root)
{
    printf("%s %i\n", line, root->value);

    for (NodePointer index = root->first_son; index; index = index->right_brother)
    {
        strcat(line, "\t");

        print_value(index);

        if (strlen(line) >= strlen("\t"))
            line[strlen(line) - strlen("\t")] = '\0';
    }
}

void create_root(NodePointer *root, const int value)
{
    if (*root)
        printf("A root already exists!\n");
    else
    {
        *root = (NodePointer)malloc(sizeof(struct Node));

        (*root)->value = value;

        (*root)->father = NULL;
        (*root)->first_son = NULL;
        (*root)->right_brother = NULL;
    }
}

void add_son(NodePointer root, const int value_of_father, const int value)
{
    NodePointer son = NULL, index = NULL;
    NodePointer father = node_pointer(root, value_of_father);

    if (father)
    {
        son = (NodePointer)malloc(sizeof(struct Node));

        son->value = value;
        son->father = father;
        son->first_son = NULL;
        son->right_brother = NULL;

        if (!(father->first_son))
            father->first_son = son;
        else
        {
            for (index = father->first_son; index->right_brother; index = index->right_brother)
                ;

            index->right_brother = son;
        }
    }
}

NodePointer initialize_tree(NodePointer root)
{
    NodePointer index = NULL, tree = NULL;

    if (root)
        tree = root;

    if (tree)
    {
        for (index = tree->first_son; index; index = index->right_brother)
            return initialize_tree(index);

        free(tree);
    }

    return NULL;
}

int father(NodePointer root, const int value)
{
    NodePointer node = NULL;

    node = node_pointer(root, value);

    return node->father->value;
}

int first_son(NodePointer root, const int value)
{
    NodePointer node = NULL;

    node = node_pointer(root, value);

    return node->first_son->value;
}

int right_brother(NodePointer root, const int value)
{
    NodePointer node = NULL;

    node = node_pointer(root, value);

    return node->right_brother->value;
}
#include "generalized-trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NodePointer node_pointer(NodePointer root, const int *value)
{
    NodePointer root2, father, index;
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

void create_root(NodePointer *root, const int *value)
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

void add_son(NodePointer root, const int *value_of_father, const int *value)
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
            for (index = father->first_son; index; index = index->right_brother);

            index->right_brother = son;
        }
    }
}
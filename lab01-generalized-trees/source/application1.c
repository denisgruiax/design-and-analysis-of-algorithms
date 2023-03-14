/*
Application 1

    void insert_root(NodePointer root, int value); - destroys the generalized tree if it exists and creates a new one with "root_key" as the root;
    int search_value(NodePointer root, int value);  - search for the key "key" in the tree; returns 1 if the key was found, or 0 otherwise;
    int delete_value(NodePointer root, int value); - searches for the key "key" in the tree and deletes it; returns 1 if the key was found and deleted, or 0 otherwise;

    void preorder(NodePointer root); - traverses the tree in preorder, displaying the keys encountered in this traversal;
    void inorder(NodePointer root); - traverses the tree out of order, displaying the keys encountered in this traversal;
    void postorder(NodePointer root); - traverses the tree in postorder, displaying the keys encountered in this traversal;

    int height_tree(NodePointer root); - returns the height of the generalized tree;
    int degree_tree(NodePointer root); - returns the degree of the generalized tree;
    int the_leftmost_brother(NodePointer root, int value); - returns the key of the leftmost sibling of the key "key" or -1 if it does not exist;
    int the_rightmost_brother(NodePointer root, int value); - returns the key of the rightmost sibling of the key "key" or -1 if it does not exist;
    int number_of_siblings(NodePointer root, int value); - returns the number of siblings of the key "key".
*/

#include "../interface/generalized-trees.h"
#include <stdio.h>
#include <stdlib.h>

void insert_root(NodePointer *root, int value)
{
    *root = initialize_tree(*root);

    create_root(root, value);
}

int search_value(NodePointer root, int value)
{
    NodePointer index = NULL;
    int result = 0;

    if (root)
    {
        if (root->value == value)
            return 1;

        for (index = root->first_son; index; index = index->right_brother)
        {
            if (index->value == value)
                return 1;

            result = search_value(index, value);
            if (result)
                return result;
        }

        return 0;
    }

    return 0;
}

int delete_value(NodePointer *root, int value)
{
    NodePointer index = NULL, father = NULL, previous_brother = NULL, current_brother = NULL, brother = NULL;

    if ((*root)->value == value)
    {
        *root = initialize_tree(*root);

        return 1;
    }

    father = node_pointer(*root, value)->father;

    if (father->first_son->value == value)
    {
        brother = father->first_son->right_brother;

        father->first_son = brother;

        for (index = father->first_son->right_brother; index->right_brother; index = index->right_brother)
            index = index->right_brother;

        initialize_tree(index->right_brother);

        return 1;
    }

    brother = node_pointer(*root, value);
    father = brother->father;

    if (father)
    {
        previous_brother = father->first_son->right_brother;
        current_brother = father->first_son->right_brother->right_brother;

        if (previous_brother->value == value)
        {
            father->first_son->right_brother = current_brother;

            return 1;
        }
        else if (current_brother->value == value)
        {
            previous_brother->right_brother = current_brother->right_brother;
            initialize_tree(current_brother);
        }
        else
        {
            if (current_brother)
            {
                for (index = current_brother; index; index = index->right_brother)
                {
                    if (index->value == value)
                    {
                        previous_brother->right_brother = index->right_brother;

                        initialize_tree(index);

                        return 1;
                    }

                    previous_brother = index;
                }
            }
        }
        return 1;
    }
    return 0;
}

void preorder(NodePointer root)
{
    NodePointer index = NULL;

    if (!root)
        return;

    printf("%i, ", root->value);

    if (root->first_son)
    {
        preorder(root->first_son);

        for (index = root->first_son->right_brother; index; index = index->right_brother)
            preorder(index);
    }
}
/*
void inorder(NodePointer root)
{
    
}
void postorder(NodePointer root)
{
    
}
int height_tree(NodePointer root)
{
}
int degree_tree(NodePointer root)
{
}
int the_leftmost_brother(NodePointer root, int value)
{
}
int the_rightmost_brother(NodePointer root, int value)
{
}
int number_of_siblings(NodePointer root, int value)
{
}
*/
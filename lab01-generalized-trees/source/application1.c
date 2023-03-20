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

    if (root)
    {
        printf("%i, ", root->value);

        if (root->first_son)
            preorder(root->first_son);

        if (root->first_son)
            if (root->first_son->right_brother)
                for (index = root->first_son->right_brother; index; index = index->right_brother)
                    preorder(index);
    }
}

void inorder(NodePointer root)
{
    NodePointer index = NULL;

    if (root)
    {
        if (root->first_son)
            inorder(root->first_son);

        printf("%i, ", root->value);

        if (root->first_son)
            if (root->first_son->right_brother)
                for (index = root->first_son->right_brother; index; index = index->right_brother)
                    inorder(index);
    }
}

void postorder(NodePointer root)
{
    NodePointer index = NULL;

    if (root)
    {
        if (root->first_son)
            postorder(root->first_son);

        if (root->first_son)
            if (root->first_son->right_brother)
                for (index = root->first_son->right_brother; index; index = index->right_brother)
                    postorder(index);

        printf("%i, ", root->value);
    }
}

int height_tree(NodePointer root)
{
    return height_tree_recursive(root) - 1;
}

static int height_tree_recursive(NodePointer root)
{
    NodePointer index = NULL;
    int height_max = 0;

    if (root->first_son)
        for (index = root->first_son; index; index = index->right_brother)
            height_max = max(height_max, height_tree_recursive(index));

    ++height_max;

    return height_max;
}

int degree_tree(NodePointer root)
{
    if (!root)
        return -1;

    if (root->first_son)
    {
        if (!root->first_son->right_brother)
            return 1;
    }
    else
        return 0;

    if (root->first_son->right_brother)
        return degree_tree_tail_recursive(root->first_son->right_brother, 1);
}

static int degree_tree_tail_recursive(NodePointer node, int degree)
{
    if (!node)
        return degree;

    degree_tree_tail_recursive(node->right_brother, ++degree);
}

int the_leftmost_brother(NodePointer root, int value)
{
    NodePointer node = node_pointer(root, value);
    if (node)
        if (node->father)
            if (node->father->first_son)
                if (node->father->first_son->value != value)
                    return node->father->first_son->value;

    return -1;
}

int the_rightmost_brother(NodePointer root, int value)
{
    NodePointer index = node_pointer(root, value);

    if (index)
        if (index->father)
            if (index->first_son)
                index = index->father->first_son;

    if (index)
        for (; index->right_brother; index = index->right_brother)
            ;

    if (index)
        if (index->value != value)
            return index->value;

    return -1;
}

int number_of_siblings(NodePointer root, int value)
{
    NodePointer node = node_pointer(root, value);

    if (!node)
        return -1;

    node = node->father;

    if (node)
        if (node->first_son)
        {
            if (!root->first_son->right_brother)
                return 1;

            return number_of_siblings_tail_recursive(node->first_son, 0);
        }

    return -1;
}

static int number_of_siblings_tail_recursive(NodePointer node, int siblings)
{
    if (!node)
        return siblings;

    number_of_siblings_tail_recursive(node->right_brother, ++siblings);
}

int depth_of_node(NodePointer node)
{
    return depth_of_node_tail_recursive(node, -1);
}

static int depth_of_node_tail_recursive(NodePointer node, int accumulator)
{
    if (!node)
        return accumulator;

    return depth_of_node_tail_recursive(node->father, ++accumulator);
}

int max(const int value, const int value2)
{
    return value > value2 ? value : value2;
}

int number_of_siblings_at_same_depth(NodePointer root, int depth)
{
    return number_of_siblings_at_same_depth_recursive(root, depth);
}

static int number_of_siblings_at_same_depth_recursive(NodePointer root, int depth)
{
    int count = 0;
    NodePointer son = root->first_son;

    if (!root)
        return 0;

    if (!depth)
        return 1;

    for (; son; son = son->right_brother)
        count += number_of_siblings_at_same_depth_recursive(son, depth - 1);

    return count;
}
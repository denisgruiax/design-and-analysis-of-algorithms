#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node *first_son;
    struct Node *right_brother;
    struct Node *father;
} GeneralizedTree;

typedef struct Node *NodePointer;

NodePointer node_pointer(NodePointer root, const int *value);
void print_value(NodePointer root);

void create_root(NodePointer *root, const int *value);
void add_son(NodePointer root, const int *value_of_father, const int *value);
NodePointer initialize_tree(NodePointer root);


int *father(NodePointer root, const int *value);
int *first_son(NodePointer root, const int *value);
int *right_brother(NodePointer root, const int *value);
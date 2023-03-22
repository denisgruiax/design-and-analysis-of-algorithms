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

NodePointer node_pointer(NodePointer root, const int value);
void print_value(NodePointer root);

void create_root(NodePointer *root, const int value);
void add_son(NodePointer root, const int value_of_father, const int value);
NodePointer initialize_tree(NodePointer root);


int father(NodePointer root, const int value);
int first_son(NodePointer root, const int value);
int right_brother(NodePointer root, const int value);

/*Application 1 requirement*/
void insert_root(NodePointer *root, int value);

int search_value(NodePointer root, int value);
int delete_value(NodePointer *root, int value);

void preorder(NodePointer root);
void inorder(NodePointer root);
void postorder(NodePointer root);

int height_tree(NodePointer root);

int degree_tree(NodePointer root);

int the_leftmost_brother(NodePointer root, int value);
int the_rightmost_brother(NodePointer root, int value);

int number_of_siblings(NodePointer root, int value);


int depth_of_node(NodePointer node);

int max(const int value, const int value2);

int number_of_siblings_at_same_depth(NodePointer root, int depth);
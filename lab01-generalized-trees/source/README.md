# Why some implementation are implemented as they are.

## Height of a tree 
```
It just an assuption you make for the recursive description of the height of a tree. You can consider a tree composed by just a node either with 0 height or with 1 height.

If you really want to think about it somehow you can think that:

    it's 0 if you consider the height as a edge count (so that a single node doesn't have any edge, hence 0)
    
    it's 1 if you consider the height as a node count (so that a single node counts as 1)

    This is just to describe how much height the smallest tree has, then in any case whenever you add a descending node you will add also a related edge so it will increase accordingly.
```

## Depth of a tree
```
    The height or maximum depth of a binary tree is the total number of edges on the longest path from the root node to the leaf node. In other words, the height of a binary tree is equal to the maximum number of edges from the root to the most distant leaf node. The height of an empty tree or tree with one node is 0.
```

## postoder and preorder recursion

```c++
void fun(int n)
{
    if (n>2)
    {
        fun(n - 1);
        fun(n - 2);
        fun(n - 3);
    }

    printf("%i ", n);
}

postorder
2 1 0 3 2 1 4 2 1 0 3 2 5

void fun2(int n)
{
    printf("%i ", n);

    if (n > 2)
    {
        fun2(n - 1);
        fun2(n - 2);
        fun2(n - 3);
    }
}

preoder
5 4 3 2 1 0 2 1 3 2 1 0 2

```
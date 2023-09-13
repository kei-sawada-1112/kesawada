#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

t_bst *bst_insert(t_bst *root, int value);

t_bst *bst_search(t_bst *root, int value);

t_bst *bst_delete(t_bst *root, int value);

t_bst *bst_insert(t_bst *root, int value)
{
    if (!root)
    {
        t_bst *new_node = (t_bst *)malloc(sizeof(t_bst));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return (new_node);
    }
    if (root->value > value)
        root->left = bst_insert(root->left, value);
    else if (root->value < value)
        root->right = bst_insert(root->right, value);

    return (root);
}

t_bst *bst_search(t_bst *root, int value)
{
    if (!root)
        return (NULL);
    else if (root->value == value)
    {
        printf("value: %d is finded here!\n", value);
        return (root);
    }
    else if (root->value < value)
        return bst_search(root->right, value);
    else if (root->value > value)
        return bst_search(root->left, value);
    return (root);
}

t_bst *bst_find_min(t_bst *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

t_bst *bst_delete(t_bst *root, int value)
{
    if (!root)
        return NULL;

    if (value < root->value)
        root->left = bst_delete(root->left, value);
    else if (value > root->value)
        root->right = bst_delete(root->right, value);
    else 
    {
        if (!root->left)
        {
            t_bst *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (!root->right)
        {
            t_bst *tmp = root->left;
            free(root);
            return tmp;
        }
        
        t_bst *tmp = bst_find_min(root->right);
        root->value = tmp->value;
        root->right = bst_delete(root->right, tmp->value);
    }
    return (root);
}

void print_bst(t_bst *root, int space)
{
    const int COUNT = 5;  // ノード間のスペースの量
    if (!root)
        return;

    space += COUNT;

    print_bst(root->right, space);

    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    print_bst(root->left, space);
}

int main()
{
    t_bst *root = NULL;
    root = bst_insert(root, 20);
    root = bst_insert(root, 10);
    root = bst_insert(root, 30);
    root = bst_insert(root, 25);
    root = bst_insert(root, 35);
    root = bst_insert(root, 22);
    root = bst_insert(root, 21);

    print_bst(root, 0);

    root = bst_delete(root, 30);

    print_bst(root, 0);

    // 必要に応じてメモリ解放処理を行ってください
    return 0;
}

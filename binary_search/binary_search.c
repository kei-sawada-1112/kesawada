#include "binary_search.h"
#include <stdlib.h>
#include <stdio.h>

t_node *bst_insert(t_node *root, int value)
{
    if (!root)
    {
        root = (t_node *)malloc(sizeof(t_node));
        if (!root)
            return NULL;
        root->value = value;
        root->left = NULL;
        root->right = NULL;
        return (root);
    }
    else
    {
        if (root->value > value)
        {
            root->left = bst_insert(root->left, value);
        }
        else if (root->value < value)
            root->right = bst_insert(root->right, value);
        else if (root->value == value)
        {
            printf("value: %d already exists.\n", value);
            return root;
        }
    }
    return root;
}

t_node *bst_find_min(t_node *root)
{
    while (root->left)
        root = root->left;
    return root;
}

t_node *bst_delete(t_node *root, int value)
{
    if (!root)
        return NULL;
    else
    {
        if (root->value == value)
        {
            if (!root->left && !root->right)
            {
                free(root);
                return NULL;
            }
            else if (!root->left)
            {
                t_node *tmp = root->right;
                free(root);
                return (tmp);
            }
            else if (!root->right)
            {
                t_node *tmp = root->left;
                free(root);
                return (tmp);
            }
            else 
            {
                t_node *tmp = bst_find_min(root->right);
                root->value = tmp->value;
                root->right = bst_delete(root->right, tmp->value);
            }
        }
        else if (root->value > value)
            root->left = bst_delete(root->left, value);
        else if (root->value < value)
            root->right = bst_delete(root->right, value);
    }
    return root;
}

t_node *bst_search(t_node *root, int value)
{
    if (!root || !value)
        return NULL;
    
    if (root->value > value)
        return bst_search(root->left, value);
    else if (root->value < value)
        return bst_search(root->right, value);
    else
        printf("value: %d founded!\n", value);
    return root;
}

void bst_inorder(t_node *root, int space)
{
    const int COUNT = 5;  // ノード間のスペースの量
    if (!root)
        return;

    space += COUNT;

    bst_inorder(root->right, space);

    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    bst_inorder(root->left, space);
}

int main()
{
    t_node *root = NULL;
    root = bst_insert(root, 20);
    root = bst_insert(root, 10);
    root = bst_insert(root, 30);
    root = bst_insert(root, 25);
    root = bst_insert(root, 35);
    root = bst_insert(root, 22);
    root = bst_insert(root, 21);
    root = bst_insert(root, 20);

    bst_inorder(root, 0);
}
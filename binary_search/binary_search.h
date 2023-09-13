#ifndef BINARY_SEARCH_H
# define BINARY_SEARCH_H

typedef struct s_node {
    int value;
    struct s_node *left;
    struct s_node *right;
} t_node;

t_node* bst_insert(t_node* root, int value);
t_node* bst_search(t_node* root, int value);
t_node* bst_delete(t_node* root, int value);
void bst_inorder(t_node* root, int space);

#endif
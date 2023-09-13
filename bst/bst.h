#ifndef BST_H
# define BST_H

typedef struct s_bst {
    int value;
    struct s_bst* left;
    struct s_bst* right;
} t_bst;

#endif
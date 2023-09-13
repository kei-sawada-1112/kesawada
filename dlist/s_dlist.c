#include <stdlib.h>
#include <stdio.h>

typedef struct s_dlist {
    int value;
    struct s_dlist* prev;
    struct s_dlist* next;
} t_dlist;

t_dlist* dlist_append(t_dlist* tail, int value);
t_dlist* dlist_prepend(t_dlist* head, int value);
void dlist_remove(t_dlist **node);

t_dlist *dlist_append( t_dlist *root, int value)
{
    if (!root)
    {
        root = (t_dlist *)malloc(sizeof(t_dlist));
        if (!root)
            return NULL;
        root->value = value;
        root->next = NULL;
        root->prev = NULL;
        return root;
    }

    t_dlist *tmp = root;
    t_dlist *new_dlist = (t_dlist *)malloc(sizeof(t_dlist));
    if (!new_dlist)
        return NULL;
    
    new_dlist->value = value;
    new_dlist->next = NULL;

    while (tmp->next)
        tmp = tmp->next;
    
    tmp->next = new_dlist;
    new_dlist->prev = tmp;
    return (root);
}

t_dlist* dlist_prepend(t_dlist* head, int value)
{
    t_dlist *new_list = (t_dlist *)malloc(sizeof(t_dlist));
    if (!new_list)
        return NULL;
    new_list->value = value;
    new_list->next = head;
    new_list->prev = NULL;

    if (head)
        head->prev = new_list;

    return (new_list);
}

void dlist_remove(t_dlist **node)
{
    if (!(*node))
        return ;

    if ((*node)->prev)
        (*node)->prev->next = (*node)->next;
    
    if ((*node)->next)
        (*node)->next->prev = (*node)->prev;

    free(*node);
    (*node) = NULL;
}
#ifndef MINPQ_H
# define MINPQ_H

typedef struct {
    int *data;
    int size;
    int capacity;
} MinPQ;

MinPQ* create_minpq(int capacity);
void insert_minpq(MinPQ* pq, int value);
int extract_min(MinPQ* pq);

#endif
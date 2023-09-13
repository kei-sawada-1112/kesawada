#include "minpq.h"
#include <stdio.h>
#include <stdlib.h>

MinPQ *create_minpq(int capacity)
{
    MinPQ *pq = (MinPQ *)malloc(sizeof(MinPQ) * capacity);
    if (!pq)
        return NULL;

    pq->data = (int *)malloc(sizeof(int) * (capacity + 1));
    if (!pq->data)
    {
        free(pq);
        return NULL;
    }

    pq->size = 0;
    pq->capacity = capacity;

    return (pq);
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert_minpq(MinPQ *pq, int value)
{
    if (!pq)
        return ;
    if (pq->size >= pq->capacity)
    {
        printf("The priority queue is full.\n");
        return ;
    }

    pq->data[++pq->size] = value;
    int k = pq->size;
    while (k > 1 && pq->data[k/2] > pq->data[k])
    {
        swap(&pq->data[k], &pq->data[k/2]);
        k /= 2;
    }
}

int extract_min(MinPQ *pq)
{
    if (pq->size == 0)
    {
        printf("The priority queue is empty.\n");
        return -1;
    }

    int min = pq->data[1];
    swap(&pq->data[1], &pq->data[pq->size]);
    pq->size--;

    int k = 1;
    while (2*k <= pq->size)
    {
        int j = 2*k;
        if (j < pq->size && pq->data[j] > pq->data[j+1])
            j++;
        if (pq->data[k] <= pq->data[j])
            break;
        swap(&pq->data[k], &pq->data[j]);
        k = j;
    }

    return min;
}

void free_minpq(MinPQ *pq)
{
    if (pq)
    {
        free(pq->data);
        free(pq);
    }
}

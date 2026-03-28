#ifndef _QUENE_H_
#define _QUENE_H_

#define MAX_QUENE_SIZE 100

typedef struct
{
    int Sequ[MAX_QUENE_SIZE];
    int rear;
    int quelen;
} CircularQuene_t;

void QueueInit(CircularQuene_t *Q);
int QueueIsFull(CircularQuene_t *Q);
int QueueIsEmpty(CircularQuene_t *Q);
int QueueEnQueue(CircularQuene_t *Q, int e);
int QueueDeQueue(CircularQuene_t *Q, int *e);

#endif
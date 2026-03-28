#ifndef _STACK_H_
#define _STACK_H_

#define MAX_STACK_SIZE 100

typedef struct 
{
    int Data[MAX_STACK_SIZE];
    int top;
} Stack_t;

void StackInit(Stack_t *S);
int StackIsEmpty(Stack_t *S);
int StackPush(Stack_t *S, int e);
int StackPop(Stack_t *S, int *e);

#endif

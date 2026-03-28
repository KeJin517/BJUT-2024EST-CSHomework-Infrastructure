/**
 * @file    Queue.c
 * @author  李岢锦
 * @brief   队列相关通用处理任务
 * @version 0.1
 * @date    2026-03-28
 * @details 基于rear和quelen的特殊循环队列操作
 */

#include "Header.h"

/// @brief 初始化循环队列
/// @param Q 
void QueueInit(CircularQuene_t *Q)
{
    if (Q == NULL)
    {
        return;
    }
    
    Q->rear = MAX_QUENE_SIZE - 1;
    Q->quelen = 0;
}

/// @brief 判断循环队列是否已满
/// @param Q 
/// @return 
int QueueIsFull(CircularQuene_t *Q)
{
    if (Q == NULL)
    {
        return 0;
    }
    return Q->quelen == MAX_QUENE_SIZE;
}

/// @brief 判断循环队列是否为空
/// @param Q 
/// @return 
int QueueIsEmpty(CircularQuene_t *Q)
{
    if (Q == NULL)
    {
        return -1;
    }
    
    return Q->quelen == 0;
}

/// @brief 入队
/// @param Q 
/// @param e 
/// @return 
int QueueEnQueue(CircularQuene_t *Q, int e)
{
    if (Q == NULL || QueueIsFull(Q))
    {
        return 0;
    }

    Q->rear = (Q->rear + 1) % MAX_QUENE_SIZE;
    Q->Sequ[Q->rear] = e;
    Q->quelen++;

    return 1;
}

/// @brief 出队
/// @param Q 
/// @param e 
/// @return 
int QueueDeQueue(CircularQuene_t *Q, int *e)
{
    if (Q == NULL || QueueIsEmpty(Q))
    {
        return 0;
    }

    int front = (Q->rear - Q->quelen + 1 + MAX_QUENE_SIZE) % MAX_QUENE_SIZE;

    *e = Q->Sequ[front];
    Q->quelen--;

    return 1;
}
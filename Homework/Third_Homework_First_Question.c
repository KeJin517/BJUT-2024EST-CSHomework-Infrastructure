/**
 * @file    Third_Homework_First_Question.c
 * @author  李岢锦
 * @brief   第三次作业 3.1
 * @version 0.1
 * @date    2026-03-28
 * @details 假设以数组sequ[m]存放循环队列的元素，同时设变量rear和quelen分别指示队尾元素的位置和内含元素的个数。试给出此循环队列的队满条件，并写出相应的入列和出列算法。
 */

#include "Header.h"

void Third_Homework_First_Question()
{
    CircularQuene_t Q;
    QueueInit(&Q);

    printf("队满条件：%d\n", MAX_QUENE_SIZE);

    for (int i = 0; i < 5; i++)
    {
        int e = i * 10;
        if (QueueEnQueue(&Q, e))
        {
            printf("元素%d入列成功，当前队列长度：%d\n", e, Q.quelen);
        }
    }
    
    int out_elm;
    for (int i = 0; i < 3; i++)
    {
        if (QueueDeQueue(&Q, &out_elm))
        {
            printf("元素%d出列成功，当前队列长度：%d\n", out_elm, Q.quelen);
        }
    }

}
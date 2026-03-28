/**
 * @file    Stack.c
 * @author  李岢锦
 * @brief   栈相关通用处理任务
 * @version 0.1
 * @date    2026-03-28
 * @details 提供标准的顺序栈基础操作
 */

#include "Header.h"

/// @brief 初始化空栈
/// @param S 
void StackInit(Stack_t *S)
{
    if (S == NULL)
    {
        return;
    }

    S->top = -1;
}

/// @brief 判断栈是否为空
/// @param S 
/// @return 
int StackIsEmpty(Stack_t *S)
{
    if (S == NULL)
    {
        return 1;
    }

    return S->top == -1;
}

/// @brief 入栈
/// @param S 
/// @param e 
/// @return 
int StackPush(Stack_t *S, int e)
{
    if (S == NULL || S->top == MAX_STACK_SIZE - 1)
    {
        return 0;
    }
    
    S->top++;
    S->Data[S->top] = e;
    return 1;
}

/// @brief 出栈
/// @param S 
/// @param e 
/// @return 
int StackPop(Stack_t *S, int *e)
{
    if (S == NULL || StackIsEmpty(S))
    {
        return 0;
    }
    
    *e = S->Data[S->top];
    S->top--;
    return -1;
}
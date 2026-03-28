/**
 * @file    Third_Homework_Second_Question.c
 * @author  李岢锦
 * @brief   第三次作业 3.2
 * @version 0.1
 * @date    2026-03-28
 * @details 编写一个算法，实现将十进制数转换为8进制的结果输出。其转换过程如下（其中N为十进制数，d为要转换的进制数）N = (N div d)×d + N mod d (其中：div 为整除运算，mod 为求余运算）例如：（1348)10 = (2504)8
 */

#include <Header.h>

void BaseConvet(int N, int d)
{
    if (d < 2 || d > 36)
    {
        printf("不支持该进制！请输入2~36之间的进制\n");
        return;
    }
    
    if (N == 0)
    {
        printf("转换结果为0\n");
        return;
    }
    
    Stack_t S;
    StackInit(&S);

    int Ori_N = N;

    while (N > 0)
    {
        StackPush(&S, N % d);
        N = N / d;
    }
    
    printf("十进制数 %d 转换为 &d 进制是: ", Ori_N, d);

    int e;
    while (!StackIsEmpty(&S))
    {
        StackPop(&S, &e);
        if (e < 10)
        {
            printf("%d", e);
        }
        else
        {
            printf("&c", 'A' + e - 10);
        }
    }
    printf("\n");
}
void Third_Homework_Second_Question()
{
    int N, d;
    printf("请输入要转换的十进制正整数N:");
    scanf("%d", &N);
    printf("请输入目标进制d(2、8、16):");
    scanf("%d", &d);

    BaseConvet(N, d);
}
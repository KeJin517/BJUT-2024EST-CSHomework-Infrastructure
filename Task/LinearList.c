/**
 * @file    SqList.c
 * @author  李岢锦
 * @brief   线性表任务
 * @version 0.1
 * @date    2026-03-15
 * @details 线性表相关通用处理任务
 */

#include "Header.h"

/// @brief 线性表初始化
/// @param LinearList 
void LinearListInit(LinearList_t *LinearList)
{
    LinearList->LinearList.MaxSize = INITSIZE;
    LinearList->LinearList.ArrLength = 0;
    LinearList->LinearList.Linearlist = (int *)malloc(INITSIZE * sizeof(int));
}

/// @brief 线性表释放内存
/// @param LinearList 
void LinearListFree(LinearList_t *LinearList)
{
    if (LinearList->LinearList.Linearlist)
    {
        free(LinearList->LinearList.Linearlist);
    }
}

/// @brief 顺序表初始化
/// @param LinearList 
void SqlistInit(LinearList_t *LinearList)
{
    LinearList->Sqlist.MaxSize = INITSIZE;
    LinearList->Sqlist.ArrLength = 0;
    LinearList->Sqlist.Sqlist_Before_Sort = (int *)malloc(INITSIZE * sizeof(int));
    LinearList->Sqlist.Sqlist_After_Sort = (int *)malloc(INITSIZE * sizeof(int));
}

/// @brief 顺序表释放内存
/// @param LinearList 
void SqlistFree(LinearList_t *LinearList)
{
    if (LinearList->Sqlist.Sqlist_Before_Sort)
    {
        free(LinearList->Sqlist.Sqlist_Before_Sort);
    }

    if (LinearList->Sqlist.Sqlist_After_Sort)
    {
        free(LinearList->Sqlist.Sqlist_After_Sort);
    }
}

/// @brief 接收用户输入的线性表
/// @param LinearList 
void LinearlistInput(LinearList_t *LinearList)
{
    
    printf("请输入线性表的长度：");
    scanf("%d", &LinearList->LinearList.ArrLength);
    
    if (LinearList->LinearList.ArrLength > LinearList->LinearList.MaxSize)
    {
        LinearList->LinearList.MaxSize = LinearList->LinearList.ArrLength;
        LinearList->LinearList.Linearlist = (int *)realloc(LinearList->LinearList.Linearlist, LinearList->LinearList.MaxSize * sizeof(int));
    }
    
    printf("请依次输入 %d 个整数（每次输入后请用空格或回车隔开）：\n", LinearList->LinearList.ArrLength);
    for (int i = 0; i < LinearList->LinearList.ArrLength; i++)
    {
        scanf("%d", &LinearList->LinearList.Linearlist[i]);
    }
    
    printf("您输入的线性表是：");
    for (int i = 0; i < LinearList->LinearList.ArrLength; i++)
    {
        printf("%d ", LinearList->LinearList.Linearlist[i]);
    }
    printf("\n");

    return;
}

/// @brief 将用户输入的乱序线性表处理为顺序表
/// @param LinearList 
void SqlistHandle(LinearList_t *LinearList)
{   
    LinearList->Sqlist.ArrLength = LinearList->LinearList.ArrLength;
    if (LinearList->Sqlist.ArrLength > LinearList->Sqlist.MaxSize) 
    {
        LinearList->Sqlist.MaxSize = LinearList->Sqlist.ArrLength;
        LinearList->Sqlist.Sqlist_Before_Sort = (int *)realloc(LinearList->Sqlist.Sqlist_Before_Sort, LinearList->Sqlist.MaxSize * sizeof(int));
        LinearList->Sqlist.Sqlist_After_Sort = (int *)realloc(LinearList->Sqlist.Sqlist_After_Sort, LinearList->Sqlist.MaxSize * sizeof(int));
    }
    memcpy(LinearList->Sqlist.Sqlist_Before_Sort, (const void*)LinearList->LinearList.Linearlist, LinearList->Sqlist.ArrLength * sizeof(int));

    for (int i = 0; i < LinearList->Sqlist.ArrLength-1; i++)
    {
        for (int j = 0; j < LinearList->Sqlist.ArrLength-1-i; j++)
        {
            if (LinearList->Sqlist.Sqlist_Before_Sort[j] > LinearList->Sqlist.Sqlist_Before_Sort[j+1])
            {
                int temp = LinearList->Sqlist.Sqlist_Before_Sort[j];
                LinearList->Sqlist.Sqlist_Before_Sort[j] = LinearList->Sqlist.Sqlist_Before_Sort[j+1];
                LinearList->Sqlist.Sqlist_Before_Sort[j+1] = temp;
            }
        }
    }
    memcpy(LinearList->Sqlist.Sqlist_After_Sort, (const void*)LinearList->Sqlist.Sqlist_Before_Sort, LinearList->Sqlist.ArrLength * sizeof(int));
    
    printf("经排序后的顺序表是：");
    for (int i = 0; i < LinearList->Sqlist.ArrLength; i++)
    {
        printf("%d ", LinearList->Sqlist.Sqlist_After_Sort[i]);
    }
    printf("\n");
}

/// @brief 清除重复元素
/// @param LinearList 
void DelRepElement(LinearList_t *LinearList)
{
    if (LinearList->Sqlist.ArrLength == 0)
    {
        printf("线性表为空！");
        return;
    } 

    for (int i = 0; i < LinearList->LinearList.ArrLength; i++)
    {
        for (int j = i+1; j < LinearList->LinearList.ArrLength; )
        {
            if (LinearList->LinearList.Linearlist[i] == LinearList->LinearList.Linearlist[j])
            {
                for (int k = j; k < LinearList->LinearList.ArrLength - 1; k++)
                {
                    LinearList->LinearList.Linearlist[k] = LinearList->LinearList.Linearlist[k+1];
                }
                LinearList->LinearList.ArrLength--;
            }
            else
            {
                j++;
            }
        }
    }
}

/// @brief 针对顺序表的快速清除重复元素
/// @param LinearList 
void Sqlist_DelRepElement(LinearList_t *LinearList)
{
    if (LinearList->Sqlist.ArrLength == 0)
    {
        printf("顺序表为空！");
        return;
    } 

    int i=0;
    for (int j = 1; j < LinearList->Sqlist.ArrLength; j++)
    {
        if (LinearList->Sqlist.Sqlist_After_Sort[i] != LinearList->Sqlist.Sqlist_After_Sort[j])
        {
            i++;
            LinearList->Sqlist.Sqlist_After_Sort[i] = LinearList->Sqlist.Sqlist_After_Sort[j];
        }
    }
    LinearList->Sqlist.ArrLength = i+1;
}

/// @brief 找到线性表中最大值和最小值并定位
/// @param LinearList 
void FindMaxAndMin(LinearList_t *LinearList)
{
    int Max_Val = LinearList->LinearList.Linearlist[0];
    int Min_Val = LinearList->LinearList.Linearlist[0];

    int Max_Pos = 0;
    int Min_Pos = 0;

    for (int i = 1; i < LinearList->LinearList.ArrLength; i++)
    {
        if (LinearList->LinearList.Linearlist[i] > Max_Val)
        {
            Max_Val = LinearList->LinearList.Linearlist[i];
            Max_Pos = i;
        }

        if (LinearList->LinearList.Linearlist[i] < Min_Val)
        {
            Min_Val = LinearList->LinearList.Linearlist[i];
            Min_Pos = i;
        }
    }   

    LinearList->LinearList.Max_Val = Max_Val;
    LinearList->LinearList.Min_Val = Min_Val;
    LinearList->LinearList.Max_Pos = Max_Pos;
    LinearList->LinearList.Min_Pos = Min_Pos;
}


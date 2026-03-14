/**
 * @file    First_Homework_First_Question.c
 * @author  李岢锦
 * @brief   第一次作业 1.1
 * @version 0.1
 * @date    2026-03-15
 * @details 已知顺序表L递增有序，试写一个算法删除顺序表中值重复的元素，使得所得结果表中各元素值均不相同（P88 4（16））
 */

#include "Header.h"

void First_Homework_First_Question()
{
    LinearList_t LinearList;

    LinearListInit(&LinearList);
    SqlistInit(&LinearList);

    LinearlistInput(&LinearList);
    SqlistHandle(&LinearList);
    Sqlist_DelRepElement(&LinearList);

    printf("删除重复元素后的顺序表是：");
    for (int i = 0; i < LinearList.Sqlist.ArrLength; i++)
    {
        printf("%d ", LinearList.Sqlist.Sqlist_After_Sort[i]);
    }
    printf("\n");

    LinearListFree(&LinearList);
    SqlistFree(&LinearList);
}
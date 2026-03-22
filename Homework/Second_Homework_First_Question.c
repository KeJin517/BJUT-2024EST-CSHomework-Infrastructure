/**
 * @file    Second_Homework_First_Question.c
 * @author  李岢锦
 * @brief   第二次作业 2.1
 * @version 0.1
 * @date    2026-03-20
 * @details 在带头结点的单链表中，插入值为b的结点在值为a的结点之前。不存在a时，将b插入到表尾。
 */

#include "Header.h"

void Second_Homework_First_Question()
{
    LinearList_t LinearList;
    LinkList_t LinkList;

    LinearListInit(&LinearList);
    LinkList = LinkListInit();

    LinearlistInput(&LinearList);
    LinkListCreate(LinkList, LinearList.LinearList.Linearlist, LinearList.LinearList.ArrLength);

    int TargetValue;
    int InsertValue;
    printf("请输入查找值:\n");
    scanf("%d", &TargetValue);

    printf("请输入插入值:\n");
    scanf("%d", &InsertValue);

    int TargetPostion = LinkListFind(LinkList, TargetValue);
    LinkListInsert(LinkList, InsertValue, TargetPostion - 1);

    LinkListPrint(LinkList);

    LinearListFree(&LinearList);
    LinkListDestroy(LinkList);
}
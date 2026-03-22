/**
 * @file Second_Homework_Third_Question.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include "Header.h"

void Second_Homework_Third_Question()
{
    LinearList_t LinearList;
    LinkList_t LinkList;

    LinearListInit(&LinearList);
    LinkList = LinkListInit();

    printf("此处请输入正整数\n");
    LinearlistInput(&LinearList);
    LinkListCreate(LinkList, LinearList.LinearList.Linearlist, LinearList.LinearList.ArrLength);

    int FeedBack = 0;

    if (LinkList == NULL || LinkList->next == NULL)
    {
        FeedBack = 0;
        printf("链表为空");
    }
    else
    {
        int max_val, min_val, max_pos, min_pos;
        LinkListFindMaxAndMin(LinkList, &max_val, &min_val, &max_pos, &min_pos);
        if (min_val % 2 != 0)
        {
            LinkListDelete(LinkList, min_pos);
            printf("处理后的链表为:\n");
            LinkListPrint(LinkList);
            FeedBack = 1;
        }
        else if (min_val % 2 == 0)
        {
            FeedBack = 2;
        }
    }
    printf("返回值为：%d", FeedBack);

    LinearListFree(&LinearList);
    LinkListDestroy(LinkList);
}
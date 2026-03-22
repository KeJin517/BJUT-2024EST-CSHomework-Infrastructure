/**
 * @file    Second_Homework_Second_Question.c
 * @author  李岢锦
 * @brief   第二次作业 2.2
 * @version 0.1
 * @date    2026-03-22
 * @details 假设有一个循环链表的长度大于1，且表中既无头结点也无头指针。已知p为指向该链表中某结点的指针，试编写算法实现在链表中删除结点p的前趋结点，要求返回指针变量p。
 */

#include "Header.h"

LinkNode* DeletePreElm(LinkNode *head)
{
    if (head == NULL || head->next == head)
    {
        return head;
    }
    
    LinkNode *Current = head->next;
    LinkNode *temp;

    while (Current->next->next != head)
    {
        Current = Current->next;
    }
    
    temp = Current->next;
    Current->next = head;
    free(temp);

    return head;
}

void Second_Homework_Second_Question()
{
    LinearList_t LinearList;
    LinkNode* Linknode;

    LinearListInit(&LinearList);
    LinearlistInput(&LinearList);
    Linknode = CircularLinkListCreate(LinearList.LinearList.Linearlist, LinearList.LinearList.ArrLength);

    int TargetValue;
    printf("请输入查找值:\n");
    scanf("%d", &TargetValue);

    LinkNode* targetnode;
    targetnode = CircularLinkListFind(Linknode, TargetValue);

    if (targetnode == NULL)
    {
        printf("未找到目标节点\n");
        return;
    }
    
    printf("原始循环列表为：\n");
    CircularLinkListPrint(targetnode);

    targetnode = DeletePreElm(targetnode);

    printf("处理后循环列表为：\n");
    CircularLinkListPrint(targetnode);

    LinearListFree(&LinearList);
    CircularLinkListDestroy(targetnode);
}


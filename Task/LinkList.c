/**
 * @file    LinkList.c
 * @author  李岢锦
 * @brief   链表相关任务
 * @version 0.1
 * @date    2026-03-19
 * @details 链表相关通用处理任务
 */

#include "Header.h"

/// @brief 链表初始化
/// @return 
LinkList_t LinkListInit()
{
    LinkList_t head = (LinkList_t)malloc(sizeof(LinkNode));
    if (head == NULL)
    {
        return NULL;
    }
    
    head->next = NULL;

    return head;
}

/// @brief 尾插法批量写入
/// @param head 
/// @param data 
/// @param n 
void LinkListCreate(LinkList_t head, int data[], int n)
{
    if (head == NULL || data == NULL || n < 0)
    {
        return;
    }

    LinkNode *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    
    for (int i = 0; i < n; i++)
    {
        LinkNode *newnode = (LinkNode *)malloc(sizeof(LinkNode));

        if (newnode != NULL)
        {
            newnode->Data = data[i];
            newnode->next = NULL;
            tail->next = newnode;
            tail = newnode;
        }
        else
        {
            return;
        }
    }
}

/// @brief 在第n个位置后插入data
/// @param head 
/// @param data 
/// @param n 
void LinkListInsert(LinkList_t head, int data, int n)
{
    if (head == NULL || n < 0)
    {
        return;
    }
    
    LinkNode *Current = head;

    int i=0;
    while (Current != NULL && i < n)
    {
        Current = Current->next;
        i++;
    }
    
    if (Current == NULL)
    {
        return;
    }
    
    LinkNode *newnode = (LinkNode *)malloc(sizeof(LinkNode));
    if (newnode != NULL)
    {
        newnode->Data = data;
        newnode->next = Current->next;
        Current->next = newnode;
    }
}

/// @brief 删除第n个节点
/// @param head 
/// @param n 
void LinkListDelete(LinkList_t head, int n)
{
    if (head == NULL || n <= 0)
    {
        return;
    }
    
    LinkNode *Current = head;

    int i=0;
    while (Current != NULL && i < n - 1)
    {
        Current = Current->next;
        i++;
    }

    if (Current == NULL || Current->next == NULL)
    {
        return;
    }

    LinkNode *temp = Current->next;
    Current->next = temp->next;
    free(temp);
}

/// @brief 销毁整个链表
/// @param head 
void LinkListDestroy(LinkList_t head)
{
    if (head == NULL)
    {
        return;
    }
    
    LinkNode *Current = head;
    LinkNode *temp;

    while (Current != NULL)
    {
        temp = Current->next;
        free(Current);
        Current = temp;
    }
}

/// @brief 打印整个链表
/// @param head 
void LinkListPrint(LinkList_t head)
{
    if (head == NULL)
    {
        return;
    }
    
    LinkNode *Current = head->next;

    while (Current != NULL)
    {
        printf("%d ", Current->Data);
        Current = Current->next;
    }
    printf("\n");
}

/// @brief 查找特定值并返回位置 注意当前只实现返回第一个特定值的位置 不支持返回所有重复特定值的位置
/// @param head 
/// @param data 
/// @return 节点位置
int LinkListFind(LinkList_t head, int data)
{
    // if (head == NULL || head->next == NULL)
    // {
    //     return -1;
    // }

    LinkNode *Current = head->next;

    int n = 1;
    while (Current != NULL)
    {
        if (Current->Data == data)
        {
            return n;
        }
        
        Current = Current->next;
        n++;
    }
    
    printf("未找到该值，已返回队尾位置\n");
    return n;
}

/// @brief 查找最大值和最小值及其位置 通过指针传递
/// @param head 
/// @param max_val 
/// @param min_val 
/// @param max_pos 
/// @param min_pos 
void LinkListFindMaxAndMin(LinkList_t head, int *max_val, int *min_val, int *max_pos, int *min_pos)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    
    LinkNode *Current = head->next;

    *max_val = Current->Data;
    *min_val = Current->Data;
    *max_pos = 1;
    *min_pos = 1;

    int Current_Pos = 1;

    while (Current != NULL)
    {
        if (Current->Data > *max_val)
        {
            *max_val = Current->Data;
            *max_pos = Current_Pos;
        }

        if (Current->Data < *min_val)
        {
            *min_val = Current->Data;
            *min_pos = Current_Pos;
        }
        
        Current = Current->next;
        Current_Pos++;
    }
}

/** 循环链表相关 **/

/// @brief 创建循环链表
/// @param data 
/// @param n 
/// @return 返回第一个节点的指针
LinkNode* CircularLinkListCreate(int data[], int n)
{
    if (data == NULL || n <= 0)
    {
        return NULL;
    }

    LinkNode *first = (LinkNode *)malloc(sizeof(LinkNode));
    first->Data = data[0];
    first->next = first;

    LinkNode *tail = first;

    for (int i = 1; i < n; i++)
    {
        LinkNode *newnode = (LinkNode *)malloc(sizeof(LinkNode));
        if (newnode != NULL)
        {
            newnode->Data = data[i];
            tail->next = newnode;
            tail = newnode;
        }
    }

    tail->next = first;
    
    return first;
}

/// @brief 打印循环链表 从传入的结点开始打印一圈
/// @param head 
void CircularLinkListPrint(LinkNode *head)
{
    if (head == NULL)
    {
        return;
    }
    
    LinkNode *Current = head;

    do
    {
        printf("%d ", Current->Data);
        Current = Current->next;
    } while (Current != head);
    
    printf("\n");
}

/// @brief 销毁循环链表
/// @param head 
void CircularLinkListDestroy(LinkNode *head)
{
    if (head == NULL)
    {
        return;
    }
    
    LinkNode *Current = head->next;
    LinkNode *temp;

    while (Current != head)
    {
        temp = Current->next;
        free(Current);
        Current = temp;
    }
    
    free(head);
}

/// @brief 查找特定值
/// @param head 
/// @param data 
/// @return 返回节点指针
LinkNode* CircularLinkListFind(LinkNode *head, int data)
{
    if (head == NULL)
    {
        return NULL;
    }

    LinkNode *Current = head;

    do
    {
        if (Current->Data == data)
        {
            return Current;
        }
        Current = Current->next;
        
    } while (Current != head);

    return NULL;
}
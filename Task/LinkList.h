#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>

typedef struct LinkNode
{
    int Data;
    struct LinkNode *next;
} LinkNode, *LinkList_t;

LinkList_t LinkListInit();
void LinkListCreate(LinkList_t head, int data[], int n);
void LinkListInsert(LinkList_t head, int data, int n);
void LinkListDelete(LinkList_t head, int n);
void LinkListDestroy(LinkList_t head);
void LinkListPrint(LinkList_t head);
int LinkListFind(LinkList_t head, int data);
void LinkListFindMaxAndMin(LinkList_t head, int *max_val, int *min_val, int *max_pos, int *min_pos);

LinkNode* CircularLinkListCreate(int data[], int n);
void CircularLinkListPrint(LinkNode *head);
void CircularLinkListDestroy(LinkNode *head);
LinkNode* CircularLinkListFind(LinkNode *head, int data);

#endif 
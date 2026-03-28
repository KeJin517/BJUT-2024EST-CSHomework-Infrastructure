#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_

#include "stdio.h"

#define INITSIZE 10
#define MAXSIZE 100

typedef struct 
{
    struct 
    {
        int ArrLength;
        int MaxSize;
        int *Linearlist;
        //int Linearlist[MAXSIZE];

        int Max_Val;
        int Min_Val;
        int Max_Pos;
        int Min_Pos;
    }LinearList;
    
    struct 
    {
        int ArrLength;
        int MaxSize;
        int *Sqlist_Before_Sort;
        int *Sqlist_After_Sort;
        // int Sqlist_Before_Sort[MAXSIZE];
        // int Sqlist_After_Sort[MAXSIZE];
    }Sqlist;
    
} LinearList_t;

void LinearListInit(LinearList_t *LinearList);
void LinearListFree(LinearList_t *LinearList);
void SqlistInit(LinearList_t *LinearList);
void SqlistFree(LinearList_t *LinearList);

void LinearlistInput(LinearList_t *LinearList);
void SqlistHandle(LinearList_t *LinearList);
void DelRepElement(LinearList_t *LinearList);
void Sqlist_DelRepElement(LinearList_t *LinearList);
void FindMaxAndMin(LinearList_t *LinearList);

extern LinearList_t LinearList;

#endif
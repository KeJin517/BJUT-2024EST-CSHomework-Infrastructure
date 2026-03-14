/**
 * @file    First_Homework_Second_Question.c
 * @author  李岢锦
 * @brief   第一次作业 1.2
 * @version 0.1
 * @date    2026-03-15
 * @details 试写一算法，在顺序表L中找出最大值和最小值的元素及其所在的位置（包含一个用学号的每一位作为一个整数的运行结果）
 */

#include "Header.h"

void First_Homework_Second_Question()
{
    LinearList_t LinearList;

    LinearListInit(&LinearList);


    printf("请在下方依次输入学号及位数\n");
    LinearlistInput(&LinearList);
    FindMaxAndMin(&LinearList);

    printf("最大值是 %d，在数组的第 %d 个位置\n", LinearList.LinearList.Max_Val, LinearList.LinearList.Max_Pos + 1);
    printf("最小值是 %d，在数组的第 %d 个位置\n", LinearList.LinearList.Min_Val, LinearList.LinearList.Min_Pos + 1);

    LinearListFree(&LinearList);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 50
#define ElemType int

typedef struct
{
    /* data */
    ElemType data[MaxSize]; // 指向固定长度数组，在声明时已经分配了数组空间
    int length; // 当前长度
} SqList;

void InitSqList(SqList *L);
bool InsertList(SqList *L, int i, ElemType e);
bool DeleteList(SqList *L, int i, ElemType *e);
int LocateElem(SqList L, ElemType e);

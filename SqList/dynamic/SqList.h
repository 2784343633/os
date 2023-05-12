#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define InitSize 10
#define ElemType int

typedef struct
{
    /* data */
    ElemType *data; // 指向第一个元素
    int Maxsize, length; // 最大元素个数和当前长度
} SqList;

void InitList(SqList *L);
bool ListInsert(SqList *L, int i, ElemType e);
bool ListDelete(SqList *L, int i, ElemType *e);
bool IncreaseSize(SqList *L, int a);
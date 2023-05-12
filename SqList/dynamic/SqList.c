#include "./SqList.h"

void InitList(SqList *L)
{
    L->data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    L->Maxsize = InitSize;
    L->length = 0;
}

bool ListInsert(SqList *L, int i, ElemType e)
{
    if (i > L->length + 1 || i < 1)
        return false;
    if (L->length == L->Maxsize)
        return false;
    for (int j = L->length; j >= i; j--) // 从后往前
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool ListDelete(SqList *L, int i, ElemType *e)
{
    if (i > L->length || i < 1)
        return false;
    *e = L->data[i-1]; // 取值
    for (int j=i; j<L->length; j++) // 从前往后 
        L->data[j-1] = L->data[j]; 
    L->length --;
    return true;
}

bool IncreaseSize(SqList *L, int a)
{
    ElemType *p = (ElemType *)malloc(sizeof(ElemType) * (L->Maxsize + a));
    if(p == NULL)
        return false;
    for(int i=0; i<L->length; i ++)
        p[i] = L->data[i];
    free(L->data); // 释放原来分配的空间
    L->data = p;
    L->Maxsize += a; // 最大容量增加a
    return true;
}

int main(void)
{
    SqList L;
    InitList(&L);
    for(int i=1; i<10; i++)
        ListInsert(&L, i, i);
    ElemType e;
    ListDelete(&L, 2, &e);
    printf("Delete %d form list\n", e);
    IncreaseSize(&L, 5);
    printf("Maxsize: %d\n", L.Maxsize);
    return 0;
}
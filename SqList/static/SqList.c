#include "./SqList.h"

void InitSqList(SqList *L)
{
    L->length = 0; // 初始化长度为零（必须）
}

bool InsertList(SqList *L, int i, ElemType e)
{
    if (i > L->length + 1 || i < 1) // 判断位序值是否合法
        return false;
    if (L->length >= MaxSize) // 判断顺序表是否满
        return false;
    for (int j = L->length; j >= i; j--) // 从后往前, 前一个挪到后一个
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++; // 长度递增
    return true;
}

bool DeleteList(SqList *L, int i, ElemType *e)
{
    if (i > L->length || i < 1) // 判断位序值是否合法
        return false;
    // if (L->length == 0) // 判断顺序表是否空，不用判读，第一个判断包含该情况
    //     return false;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++) // 从前往后，后一个挪到前一个
        L->data[j - 1] = L->data[j];
    L->length--; // 长度递减
    return true;
}

int LocateElem(SqList L, ElemType e) // 按值查找
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1; // 返回位序
    }
    return 0;
}

int main(void)
{
    SqList L;
    ElemType e;
    InitSqList(&L);
    for (int i = 1; i < 10; i++)
        InsertList(&L, L.length + 1, i);
    DeleteList(&L, 4, &e);
    printf("Delete %d from list\n", e);
    int i = LocateElem(L, 3);
    printf("3 locatation:%d\n", i);
    return 0;
}
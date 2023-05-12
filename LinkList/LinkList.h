#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int

typedef struct LNode
{
    /* data */
    ElemType data;
    struct LNode *next;
} LNode, *LinkList; // LNode强调结点，LinkList强调链表本身

LinkList List_HeadInsert(LinkList L);
LinkList List_TailInsert(LinkList L);

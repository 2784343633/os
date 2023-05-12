#include "./LinkList.h"

LinkList List_HeadInsert(LinkList L)
{   /* 逆向建立单链表 */
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    ElemType e;
    LNode *s = NULL;
    scanf("%d", &e);
    while (e != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        /* 每次将s插入到位序为1的位置，存储顺序与输入顺序相反 */
        s->next = L->next; 
        L->next = s;
        scanf("%d", &e);
    }
    return L;
}
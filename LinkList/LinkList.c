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
        /* 前插操作 */
        s->next = L->next; 
        L->next = s;
        scanf("%d", &e);
    }
    return L;
}

LinkList List_TailInsert(LinkList L)
{   /* 正向建立单链表 */
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL; // 此处非必需
    LNode *s, *r=L;
    ElemType e;
    scanf("%d", &e);
    while(e != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        // 后插操作
        // s->next = r->next; 减少执行语句
        r->next = s; 
        r = s; // 更新尾结点指针
        scanf("%d", &e);
    }
    r->next = NULL; // 尾结点指针置空
    return L;
}


int main(void)
{
    LinkList L;
    L = List_TailInsert(L);
    return 0;
}
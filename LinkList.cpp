#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//创建
LinkList CreateLinkedList_L(){
    LinkList L;
    L->next = NULL;
    L->data = 0;
    return L;
}

//求长度
int ListLength_L(LinkList L){
    LinkList p = L;
    int k = 0;
    while(p){
        k++;
        p = p->next;
    }
    return k;
}

//查找
LNode* LocateElem_L(LinkList L, ElemType e){
    LNode* p = L;
    while(p && p->data != e){
        p = p->next;
    }
    return p;
}

//插入(头指针)
void ListInsert_L(LinkList &L, LNode *p, LNode *s){
    if(p == L){
        s->next = L;
        L = s;
    }else{
        LNode *q = L;
        while(q->next != p)     q = q->next;
        q->next = s;
        s->next = p;
    }
}

//删除
void ListDelete_L(LinkList &L,LNode *p, ElemType e){
    if(p == L){
        L = p->next;
    }else{
        LNode *q;
        while (q->next != p)
        {
            q = q->next;
        }
        e = p->data;
        delete p;
    }
}

/*
其他算法
*/

//逆序创建链表
void CreateList_L(LinkList &L, ElemType A[], int n){
    L = NULL;
    for(int i = n-1; i >= 0; --i){
        LNode *s = new LNode;
        s->data = A[i];
        s->next = L;
        L = s;
    }
}

//逆置单链表
void InvertLinkedList(LinkList &L){
    LNode* p = L;
    L = NULL;
    while(p){
        LNode *s = new LNode;
        s = p;
        s->next = L;
        L = s;
    }
}

//循环链表
LinkList CreateCircularLinkedList_L(){
    LinkList L;
    L->next = L;
    L->data = 0;
    return L;
}

/*
双向链表
*/

typedef struct DulNode
{
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
}DulNode, *DuLinkList;

//插入
void ListInsert_Dul(DuLinkList &L, DulNode *p, DulNode *s){
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
}

//删除
void ListDelete_Dul(DuLinkList &L, DulNode *p, ElemType e){
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
}


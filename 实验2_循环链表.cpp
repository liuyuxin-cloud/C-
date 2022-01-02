#include <stdio.h>
#include <stdlib.h>

//定义存放26个英文字母的链表使其能循环输出
typedef struct Lnode{
    char data;
    struct Lnode* next;
}Lnode,*LinkList;


void createList(LinkList L){

    Lnode *q;
    q = L;
    q->data = 'A';
    for(int i=0 ; i<25 ; i++){
        Lnode *p = (Lnode*)malloc(sizeof(Lnode));
        p->data = 'B'+i;
        q->next = p;
        q = p;
    }
    q->next = L;
    L = q;
}

void printList(LinkList L,int pos){
    Lnode *p;
    p = L; 
    while(pos < 0){
        pos += 26;
    }
    for(int i=0 ; i<pos ; i++){
        p = p->next;
    }
    for(int i=0 ; i<26 ; i++){
        printf("%c",p->data);
        p = p->next;
    }
}

int main(){
    
    LinkList head = (LinkList)malloc(sizeof(Lnode));
    head->next = NULL;
    createList(head);
    printList(head,28);
    return 0;
}
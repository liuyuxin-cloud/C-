#include<iostream>
#include "Stack.cpp"
using namespace std;

struct CSTree
{
    int data;
    struct CSTree *lchild, *rsubling;
};

void outPath(CSTree* T, SqStack &S){
    while(T != NULL){
        int e;
        Push_Sq(S,T->data);
        if(!T->lchild){
            StackTraverse_Sq(S);
        }else{
            outPath(T->lchild, S);
        }
        Pop_Sq(S, e);
        T = T->rsubling;
    }
}

void outPath2(CSTree *T, SqStack S){
    if(T){
        Push_Sq(S, T);
        while(!StackEmpty_Sq(S)){
            CSTree *e = GetTop_Sq(S);
            while(e->lchild){
                e = e->lchild;
                Push_Sq(S, T);
            }
            StackTraverse_Sq(S);
            Pop_Sq(S, e);
            while(!e->rsubling && !StackEmpty_Sq(S)){//当这个节点无兄弟且栈不空时进行回溯
                Pop_Sq(S, e);
            }
            if(e->rsubling){//有兄弟则入栈输出路径
                Push_Sq(S, e->rsubling);
            }
        }
    }
}
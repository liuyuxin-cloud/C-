#include<iostream>
using namespace std;

typedef struct BitNode
{
    /* data */
    int data;
    struct BitNode* lchild;
    struct BitNode* rchild; 
}BitNode, *BiTree;

void insert_BST(BiTree &T, int e){
    BiTree s = new BitNode;
    BiTree p, f;
    s->data = e;
    s->lchild = NULL;
    s->rchild = NULL;
    if(!T) T = s;
    else{
        p = T;
        while(p){
            if(e < p->data){
                f = p;
                p = p->lchild;
            }else{
                f = p;
                p = p->rchild;
            }
        }//循环结束时p为NULL，则s是p的左孩子或右孩子
        if(e < f->data){
            f->lchild = s;
        }else{
            f->rchild = s;
        }
    }
}

void inorder(BiTree T){
    if(T){
        inorder(T->lchild);
        cout << T->data << " ";
        inorder(T->rchild);
    }
}

int main(){
    int a[12] = {1,5,8,4,6,2,3,9,77,14,25,36};
    BiTree T = NULL;
    for(int i = 0; i < 12; i++){
        insert_BST(T, a[i]);
    }
    inorder(T);
}
#include<iostream>
using namespace std;

typedef struct BiThrNode{
    int data;
    struct BiThrNode *lchild, *rchild;
    struct BiThrNode *pred, *succ;
}BiThrNode, *BiThrTree;

void InorderThreading(BiThrTree &H, BiThrTree root){
    //建立以root为根的二叉树的中序全线索链表，H指向该线索链表的头结点
    H = new BiThrNode;
    H->lchild = root;
    H->rchild = NULL;
    BiThrTree pre;
    if(root == NULL){//空树头结点的线索指向头结点本身
        H->pred = H;
        H->succ = H;
    }
    else{//非空树头结点的连接
        pre = H;
        InThreading(root, pre);
        pre->succ = H;
        H->pred = pre;
    }
}

void InThreading(BiThrTree root, BiThrTree &pre){
    //对root所指向的根节点进行中序遍历，在遍历过程中线索化
    if(root != NULL){
        InThreading(root->lchild, pre);
        pre->succ = root;
        root->pred = pre;
        pre = root;
        InThreading(root->rchild, pre);
    }
}

void preThreading(BiThrTree root, BiThrTree &pre){
    if(root != NULL){
        pre->succ = root;
        root->pred = pre;
        pre = root;
    }
    preThreading(root->lchild, pre);
    preThreading(root->rchild, pre);
}
#include<iostream>
using namespace std;

typedef struct BitNode
{
    /* data */
    int data;
    struct BitNode* lchild;
    struct BitNode* rchild; 
}BitNode, *BiTree;

BiTree GetTreeNode(int data, BitNode* left, BitNode* right){
    BiTree node = new BitNode;
    node->data = data;
    node->lchild = left;
    node->rchild = right;
}

BiTree CopyTree(BiTree root){
    if(root == NULL)    return NULL;
    BiTree newlptr, newrptr;
    if(root->lchild){
        newlptr = CopyTree(root->lchild);
    }else{
        newlptr = NULL;
    }
    if(root->rchild){
        newrptr = CopyTree(root->rchild);
    }else{
        newrptr = NULL;
    }
    BiTree node = GetTreeNode(root->data, newlptr, newrptr);
    return node;
}
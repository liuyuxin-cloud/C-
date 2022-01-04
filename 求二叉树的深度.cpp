#include<iostream>
using namespace std;

typedef struct BitNode
{
    /* data */
    int data;
    struct BitNode* lchild;
    struct BitNode* rchild; 
}BitNode, *BiTree;


int BiTreeDepth(BitNode* root){
    if(root == NULL)    return 0;
    else{
        int ldepth = BiTreeDepth(root->lchild);
        int rdepth = BiTreeDepth(root->rchild);
        return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
    }
}
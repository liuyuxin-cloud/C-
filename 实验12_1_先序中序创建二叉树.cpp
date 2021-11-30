#include<iostream>
using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void buildTreePI(BiTree &T, int preorder[], int inorder[], int pre_start, int pre_end, int in_start, int in_end){
    if(pre_start == pre_end){
        return;
    }
    T->data = preorder[pre_start];
    int root_index = 0;
    for(int i = in_start; i < in_end; i++){
        if(inorder[i] == preorder[pre_start]){
            root_index = i;
            break;
        }
    }
    BiTree left = new BiTNode;
    left->lchild = NULL;
    left->rchild = NULL;
    T->lchild = left;
    BiTree right = new BiTNode;
    right->lchild = NULL;
    right->rchild = NULL;
    T->rchild = right;
    int leftNum = root_index - in_start;
    buildTreePI(left, preorder, inorder, pre_start+1, pre_start + leftNum + 1, in_start, root_index);
    buildTreePI(right, preorder, inorder, pre_start + leftNum + 1, pre_end, root_index+1, in_end);
}

void showpreorder(BiTree T){
    if(T != NULL){
        cout << T->data << " ";
        showpreorder(T->lchild);
        showpreorder(T->rchild);
    }   
}

int main(){
    int preorder[9] = {1,2,4,5,8,3,6,9,7};
    int inorder[9] = {4,2,8,5,1,6,9,3,7};
    int len = 9;
    BiTree T = new BiTNode;
    T->lchild = NULL;
    T->rchild = NULL;
    buildTreePI(T, preorder, inorder, 0, 9, 0, 9);
    showpreorder(T);
}
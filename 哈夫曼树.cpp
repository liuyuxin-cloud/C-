#include<iostream>
using namespace std;

typedef struct{
    int weight;
    int lchild, rchild;
}HTNode;

typedef struct{
    HTNode *HTree;
    int root;
}HuffmanTree;

void Select(HTNode* t, int n, int& ans1, int& ans2){
//TODO: 选出n个数中最小的两个。
}

void CreateHuffmanTree(HuffmanTree &HT, int *w, int n){
    if(n <= 1)  return;
    int m = 2 * n - 1;//树所有节点个数
    HT.HTree = new HTNode[m];
    HTNode *p = HT.HTree;
    for(int i = 0; i < n; i++, p++, w++){//初始化n个叶结点
        *p = {*w, -1, -1};
    }
    for(int i = n; i < m; i++){
        *p = {0, -1, -1};
    }
    for(int i = n; i < m; i++){
        int s1, s2;
        Select(HT.HTree, i-1, s1, s2);
        HT.HTree[i].lchild = s1;
        HT.HTree[i].rchild = s2;
        HT.HTree[i].weight = HT.HTree[s1].weight + HT.HTree[s2].weight;
    }
    HT.root = m - 1;
}
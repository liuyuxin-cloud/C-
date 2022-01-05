#include<iostream>
using namespace std;

//图的邻接表存储形式
const int MAX_VERTEX_NUM = 20;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    int data;
    ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
    int kind;
}ALGraph;

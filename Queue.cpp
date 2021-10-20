#include <iostream>
using namespace std;

typedef int QElemType;
typedef struct{
    QElemType *elem;
    int front;
    int rear;
    int queuesize;
    int incrementsize;
}SqQueue;

void InitQueue_Sq(SqQueue &Q, int maxsize, int increzise){
    Q.elem = new QElemType[maxsize + 1];
    Q.queuesize = maxsize + 1;
    Q.incrementsize = increzise;
    Q.front = Q.rear = 0;
}

int QueueLength_Sq(SqQueue Q){
    return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

void incrementQueuesize(SqQueue &Q){
    QElemType *a = new QElemType[Q.queuesize + Q.incrementsize];
    for(int k = 0; k < Q.queuesize - 1; k++){
        a[k] = Q.elem[(Q.front + k) % Q.queuesize];
    }
    delete[] Q.elem;
    Q.elem = a;
    Q.front = 0;
    Q.rear = Q.queuesize - 1;
    Q.queuesize += Q.incrementsize;
}

void EnQueue_Sq(SqQueue &Q, QElemType e){
    if((Q.rear + 1) % Q.queuesize == Q.front){
        incrementQueuesize(Q);
    }
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.queuesize;
}



bool DeQueue_Sq(SqQueue &Q, QElemType &e){
    if(Q.front == Q.rear)   return false;
    e = Q.elem[Q.front];
    Q.front = (Q.front + 1) % Q.queuesize;  return true;
}
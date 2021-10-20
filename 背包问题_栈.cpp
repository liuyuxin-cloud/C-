#include <iostream>
#include "Stack.cpp"
using namespace std;

void knapstack(int w[], int T, int n){
    SqStack S;
    InitStack_Sq(S);
    int k = 0;
    do{
        while(T > 0 && k < n){     //背包还有容量
            if(T - w[k] >= 0){     //可以放下w[k]
                Push_Sq(S, k);     //入栈
                T -= w[k];         //空间减少
            }
            k++;
        }
        if(T == 0)  
            StackTraverse_Sq(S);
        Pop_Sq(S, k);              //取出前一个物品，继续向后试探
        T += w[k];
        k++;
    }while(!StackEmpty_Sq(S) || k < n);
}
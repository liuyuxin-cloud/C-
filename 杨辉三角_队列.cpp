#include <iomanip>
#include "Queue.cpp"
using namespace std;

void Yanghui(int n){
    SqQueue Q;
    int s;
    int e;
    for(int i = 1; i <= n; i++){
        cout << ' ';
    }
    cout << '1' << endl;
    InitQueue_Sq(Q, n+2);
    EnQueue_Sq(Q, 0);
    EnQueue_Sq(Q, 1);
    EnQueue_Sq(Q, 1);
    int k = 1;
    while(k < n){
        for(int i = 1; i <= n-k; i++){
            cout << ' ';
        }
        EnQueue_Sq(Q, 0);
        do{    
            DeQueue_Sq(Q, s);
            GetHead_Sq(Q, e);
            if(e){
                cout << e << ' ';
            }else{
                cout << endl;
            }
            EnQueue_Sq(Q, s+e);
        }while(e != 0);
        k++;
    }
    DeQueue_Sq(Q, e);
    while(!QueueLength_Sq(Q) == 0){
        DeQueue_Sq(Q, e);
        cout << e << ' ';
    }
}
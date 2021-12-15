#include<iostream>
using namespace std;

int main(){
    int test[5][5] = {0,10,INT_FAST16_MAX,30,100,
                    INT_FAST16_MAX,0,50,INT_FAST16_MAX,INT_FAST16_MAX,
                    INT_FAST16_MAX,INT_FAST16_MAX,0,INT_FAST16_MAX,10,
                    INT_FAST16_MAX,INT_FAST16_MAX,20,0,60,
                    INT_FAST16_MAX,INT_FAST16_MAX,INT_FAST16_MAX,INT_FAST16_MAX,0};
    int disk[5] = {0};
    int s[5] = {1,0,0,0,0};
    int path[5][5] = {0};
    int num[5] = {0};//到终点经过的节点个数进行计数
    for(int i = 0; i < 5; i++){
        disk[i] = test[0][i];
    }   
    for(int j = 0; j < 4; j++){
        int temp;
        long int flag = INT_FAST16_MAX;         
        for(int i = 0; i < 5; i++){
            if(s[i] == 0){
                flag = flag < disk[i] ? flag : disk[i]; 
                temp = flag < disk[i] ? temp : i; 
            }
        }  
        s[temp] = 1;//终点为temp的最短路径已经找到
        path[temp][num[temp]] = temp;
        for(int i = 0; i < 5; i++){
            if(disk[temp] + test[temp][i] < disk[i]){//终点为i的最短路径更新由temp到i
                if(disk[i] < INT_FAST16_MAX){
                    
                }
                disk[i] = disk[temp] + test[temp][i];
                path[i][num[i]] = temp;
                num[i]++;
            }
        }
    }
    for(int i = 0; i < 5; i++){
        if(s[i] == 1){
            cout << i << " " << disk[i] << " ";
            for(int j = 0; j < 5; j++){
                if(path[i][j] != 0){
                    cout << path[i][j] << " ";
                }
            }
            cout << endl;
        }
    } 
}
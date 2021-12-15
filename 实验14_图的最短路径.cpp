#include<iostream>
using namespace std;

//我的解法路径不对得数正确

// int main(){
//     int test[5][5] = {0,10,INT_FAST16_MAX,30,100,
//                     INT_FAST16_MAX,0,50,INT_FAST16_MAX,INT_FAST16_MAX,
//                     INT_FAST16_MAX,INT_FAST16_MAX,0,INT_FAST16_MAX,10,
//                     INT_FAST16_MAX,INT_FAST16_MAX,20,0,60,
//                     INT_FAST16_MAX,INT_FAST16_MAX,INT_FAST16_MAX,INT_FAST16_MAX,0};
//     int disk[5] = {0};
//     int s[5] = {1,0,0,0,0};
//     int path[5][5] = {0};
//     int num[5] = {0};//到终点经过的节点个数进行计数
//     for(int i = 0; i < 5; i++){
//         disk[i] = test[0][i];
//     }   
//     for(int j = 0; j < 4; j++){
//         int temp;
//         long int flag = INT_FAST16_MAX;         
//         for(int i = 0; i < 5; i++){
//             if(s[i] == 0){
//                 flag = flag < disk[i] ? flag : disk[i]; 
//                 temp = flag < disk[i] ? temp : i; 
//             }
//         }  
//         s[temp] = 1;//终点为temp的最短路径已经找到
//         path[temp][num[temp]] = temp;
//         for(int i = 0; i < 5; i++){
//             if(disk[temp] + test[temp][i] < disk[i]){//终点为i的最短路径更新由temp到i
//                 if(disk[i] < INT_FAST16_MAX){
                    
//                 }
//                 disk[i] = disk[temp] + test[temp][i];
//                 path[i][num[i]] = temp;
//                 num[i]++;
//             }
//         }
//     }
//     for(int i = 0; i < 5; i++){
//         if(s[i] == 1){
//             cout << i << " " << disk[i] << " ";
//             for(int j = 0; j < 5; j++){
//                 if(path[i][j] != 0){
//                     cout << path[i][j] << " ";
//                 }
//             }
//             cout << endl;
//         }
//     } 
// }


const int NUM = 5;
const int INF = 9999;

int min(int dist[NUM], int flag[NUM]){
    int i, j = 0;
    int minval = INF;
    for(i = 0; i < NUM; i++){
        if(!flag[i] && dist[i] < minval){
            minval = dist[i];
            j = i;
        }
    }
    if(minval < INF){
        return j;
    }
    else{
        return -1;
    }
}

void dijistra(int edge[NUM][NUM], int s){
    int i, j, k;
    int dist[NUM] = {0};
    int path[NUM];
    int flag[NUM] = {0};
    flag[s] = 1;
    for(i = 0; i < NUM; i++){
        dist[i] = edge[s][i];
        path[i] = s;
    }
    for(i = 0; i < NUM-1; i++){
        k = min(dist, flag);
        if(k == -1) break;
        flag[k] = 1;
        for(j = 0; j < NUM; j++){
            if(!flag[j] && edge[k][j] < INF && dist[k] + edge[k][j] < dist[j]){
                dist[j] = dist[k] + edge[k][j];
                path[j] = k;
            }
        }
    }
    for(i = 0; i < NUM; i++){
        if(i != s && dist[i] < INF){
            k = i;
            cout << dist[k] << ":";
            while(k != s){
                cout << k << "-";
                k = path[k];
            }
            cout << s << endl;
        }
    }
}

int main(){
    int test[5][5] = {0,10,INF,30,100,
                    INF,0,50,INF,INF,
                    INF,INF,0,INF,10,
                    INF,INF,20,0,60,
                    INF,INF,INF,INF,0};
    dijistra(test, 0);                
}
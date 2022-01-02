#include<iostream>
using namespace std;
const int MAXSIZE = 12;

typedef struct {
    int row, col;
    int e;
}Triple;

typedef struct {
    Triple data[MAXSIZE+1];
    int mu, nu, tu;
}TSMatrix;

void Translate(int T[3][4], TSMatrix &M){
    M.mu = 3;
    M.nu = 4;
    M.tu = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(T[i][j] != 0){
                M.data[M.tu].row = i;
                M.data[M.tu].col = j;
                M.data[M.tu++].e = T[i][j]; 
            }
        }
    }
}

void add(TSMatrix s1, TSMatrix s2, TSMatrix &ans){
    int m = s1.mu;
    int n = s1.nu;
    ans.tu = 0;
    ans.mu = 3;
    ans.nu = 4;
    int t1 = 0, t2 = 0;
    while(t1 < s1.tu && t2 < s2.tu){
        if(s1.data[t1].row == s2.data[t2].row && s1.data[t1].col == s2.data[t2].col){//同位置元素直接相加
            ans.data[ans.tu].row = s1.data[t1].row;
            ans.data[ans.tu].col = s1.data[t1].col;
            ans.data[ans.tu++].e = s1.data[t1++].e +s2.data[t2++].e;
        }else if(s1.data[t1].row == s2.data[t2].row && s1.data[t1].col < s2.data[t2].col){//行等，列不等
            ans.data[ans.tu].row = s1.data[t1].row;
            ans.data[ans.tu].col = s1.data[t1].col;
            ans.data[ans.tu++].e = s1.data[t1++].e;
        }else if(s1.data[t1].row == s2.data[t2].row && s1.data[t1].col > s2.data[t2].col){
            ans.data[ans.tu].row = s2.data[t2].row;
            ans.data[ans.tu].col = s2.data[t2].col;
            ans.data[ans.tu++].e = s2.data[t2++].e;
        }else if(s1.data[t1].row < s2.data[t2].row){//行不等
            ans.data[ans.tu].row = s1.data[t1].row;
            ans.data[ans.tu].col = s1.data[t1].col;
            ans.data[ans.tu++].e = s1.data[t1++].e;
        }else{
            ans.data[ans.tu].row = s2.data[t2].row;
            ans.data[ans.tu].col = s2.data[t2].col;
            ans.data[ans.tu++].e = s2.data[t2++].e;
        }
    }
}

int main(){
    int x1[3][4] = {0,0,1,0,2,0,0,1,0,1,0,0};
    int x2[3][4] = {1,0,2,0,1,0,1,0,0,0,0,1};
    TSMatrix s1, s2, ans;
    Translate(x1, s1);
    Translate(x2, s2);
    add(s1, s2, ans);
    for(int i = 0; i < ans.tu; i++){
        cout << ans.data[i].e << " ";
    }
}
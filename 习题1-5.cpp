#include<iostream>
using namespace std;

int fun(int a[],int x0,int n){
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += a[i] * pow(x0,i);
    }
    return sum;
}

int main(){
    int a[100],n,x0，sum;
    cout << "请输入多项式阶数";
    cin >> n;
    cout << "请输入依次输入系数";
    for(i=0 ; i<n ; i++){
        cin >> a[i];
    }
    cout << "请输入未知数x0的值";
    cin >> x0;
    sum = fun(a,x0,n);
    return 0;
}
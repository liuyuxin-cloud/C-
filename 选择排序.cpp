#include<iostream>
using namespace std;

void SelectSort(int a[], int n){
    int i, j, k;
    for(i = 0; i < n - 1; i++){
        int temp = i;
        for(j = i + 1; j < n; j++){
            temp = a[temp] < a[j] ? temp : j;
        }
        if(temp != i){
            k = a[i];
            a[i] = a[temp];
            a[temp] = k;
        }
    }
}

int main(){
    int a[10] = {1,5,8,7,6,9,4,3,2,0};
    SelectSort(a, 10);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
}
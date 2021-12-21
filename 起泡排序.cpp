#include<iostream>
using namespace std;

void BubbleSort(int a[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){
    int a[10] = {1,5,8,7,6,9,4,3,2,0};
    BubbleSort(a, 10);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
}
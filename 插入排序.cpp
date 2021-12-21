#include<iostream>
using namespace std;

void InsertSort(int a[], int n){
    int i, j, temp;
    for(i = 1; i < n; i++){
        temp = a[i];
        for(j = i - 1; temp < a[j]; j--){
            a[j+1] = a[j];   
        }
        a[j+1] = temp;
    }    
}
 
int main(){
    int a[10] = {1,5,8,7,6,9,4,3,2,0};
    InsertSort(a, 10);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
}
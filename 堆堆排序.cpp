#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int lchild = 2 * i;
    int rchild = 2 * i + 1;
    if(lchild < n && arr[lchild] > arr[largest])    largest = lchild;
    if(rchild < n && arr[rchild] > arr[largest])    largest = rchild;
    if(largest != i)   {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    } 
}

void heapSort(int arr[], int len){
    //初始建堆
    for(int i = len / 2; i > 0; i--){
        heapify(arr, len, i);
    }
    
    for(int i = len - 1; i > 0; i--){
        swap(arr[i], arr[1]);
        heapify(arr, i, 1);
    }

}

int main(){
    int a[10] = {1,5,8,7,6,9,4,3,2,0};
    heapSort(a, 10);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
}
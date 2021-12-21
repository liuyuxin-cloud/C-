#include<iostream>
using namespace std;

int QuickSort(int a[], int low, int high){
    int temp = a[low];//设low为枢轴，保存值；
    while(low < high){
        while(a[high] > temp && low < high) {
            high--;
        }
        if(low < high){
            a[low++] = a[high];
        }
        while(a[low] < temp && low < high){
            low++;
        }
        if(low < high){
            a[high--] = a[low];
        }
    }
    a[low] = temp;
    return low;
}

void QSort(int a[], int low, int high){
    if(low < high){
        int key = QuickSort(a, low, high);
        QSort(a, low, key - 1);
        QSort(a, key + 1, high);
    }
}

int main(){
    int a[10] = {1,5,8,7,6,9,4,3,2,0};
    QSort(a, 0, 10);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
}
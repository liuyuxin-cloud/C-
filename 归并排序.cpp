#include<iostream>
using namespace std;

void merge(int a[], int b[], int left, int mid, int right){
    int l_pos = left, r_pos = mid+1;
    int i = left;
    while(l_pos <= mid && r_pos <= right){
        if(a[l_pos] < a[r_pos]) b[i++] = a[l_pos++];
        else    b[i++] = a[r_pos++]; 
    }
    while(l_pos <= mid) b[i++] = a[l_pos++];
    while(r_pos <= right) b[i++] = a[r_pos++];
    while(left <= right){
        a[left] = b[left];
        left++;
    }
}

void mergeSort(int a[], int b[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(a, b, left, mid);
        mergeSort(a, b, mid+1, right);
        merge(a, b, left, mid, right);
    }
}

int main(){
    int a[10] = {1,5,8,7,6,9,4,3,2,0};
    int b[10] = {0};
    mergeSort(a, b, 0, 9);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
}
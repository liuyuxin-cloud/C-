#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int temp[],int left,int mid,int right){
    
    int l_pos = left;
    int r_pos = mid+1;
    int pos = left;

    while(l_pos <= mid && r_pos <= right){
        if(arr[l_pos]%2==1 && arr[r_pos]%2==0 || (arr[l_pos]+arr[r_pos])%2==0 && arr[l_pos]<=arr[r_pos]){
            temp[pos++] = arr[l_pos++];
        }else{
            temp[pos++] = arr[r_pos++];
        }
    }

    while(l_pos <= mid) temp[pos++] = arr[l_pos++];
    while(r_pos <= right) temp[pos++] = arr[r_pos++];

    while(left <= right){//将归并的这一部分复制到原数组中
		arr[left] = temp[left];
		left++; 
	} 

}

void mergeSort(int arr[],int temp[],int left,int right){
    
    if(left < right){
        int mid = (left+right) / 2;
        mergeSort(arr,temp,left,mid);
        mergeSort(arr,temp,mid+1,right);
        merge(arr,temp,left,mid,right);
    }

}

int main(){
    int arr[10] = {1,7,9,3,4,5,8,6,2,10};
    int n = 10,i;
    int temp[10] = {0};
    mergeSort(arr,temp,0,n-1);
    for( i=0 ; i<n ; i++){
    	printf("%d ",arr[i]) ;
    }
} 
#include <iostream>
using namespace std;

//实现三路快排
typedef struct sqlist{
    int *elem;
    int length;
}sqlist;

void quicksort(sqlist L, int low, int high){

    int i = low-1;      //i指向小于枢轴的最后一个元素
    int j = low;        //j指向当前待考察的元素
    int k = high+1;     //k指向大于枢轴的第一个元素
    int piv,tmp;
    piv = L.elem[low];      //取最左边的元素作为枢轴

    if(low >= high) return;
    
    while(j<k){

        if(L.elem[j] < piv){ //当前待考察元素小于枢轴则将其与小于区最后一个交换
            
            i++;
            tmp = L.elem[j];
            L.elem[j] = L.elem[i];
            L.elem[i] = tmp;
            j++;

        }else if(L.elem[j] > piv){//当前待考察元素大于枢轴则将其与大于区第一个交换
            
            k--;
            tmp = L.elem[j];
            L.elem[j] = L.elem[k];
            L.elem[k] = tmp;
            j++;

        }else{
            j++;
        }
    
    }

    quicksort(L,low,i);
    quicksort(L,k,high);
}

int main(){
    
    int a[10] = {2,2,2,1,1,1,4,4,3,3};
    sqlist L;
    L.elem = a;
    L.length = 10;
    quicksort(L,0,L.length-1);
    for(int i=0 ; i<L.length ; i++){
            cout << L.elem[i] << " ";
    }
}
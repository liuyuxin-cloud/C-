#include <iostream>
using namespace std;

const int MAX_NUM_OF_KEY = 10;  //关键字个数
const int RADIX = 10;            //关键字基数
const int MAXSIZE = 10000;
const int bitsnum = 3;

typedef int KeysType;
typedef int InfoType;

typedef struct 
{
    KeysType keys[MAX_NUM_OF_KEY];  //关键字
    InfoType otheritems;            //其他数据项
    int bitsnum;                    //关键字的位数
}RcdType;

void RadixSort(int a[], int n){
    int C[n];       //开辟同等大小的辅助空间用于复制数据
    int i = bitsnum-1;
    while(i >= 0){
        RadixPass(a, C, n, i);      //对L进行一趟奇数排序，排序结果存入C
        i--;
        if(i >= 0){
            RadixPass(C,a,n,i);     //对C进行一趟奇数排序，排序结果存入L
            i--;
        }
        else{
            for(int j=0 ; j<n ; ++j){
                a[j] = C[j];
            }
        }
    }
}

void RadixPass(int A[], int B[], int n, int i){
    //对数组A中记录关键字的“第i位”计数，并按计数数组count的值
    //将A中记录复制到B中
    int count[RADIX];
    for(int j=0 ; j<RADIX ; ++j){   //计数数组初始化为0
        count[j] = 0;
    }
    for(int k=0 ; k<n ; ++k){       //对关键字的第i位“计数”
        count[A[k].keys[i]]++;
    }
    for(int j=1 ; j<RADIX ; ++j){
        count[j] = count[j-1] + count[j];       //累加操作
    }
    for(int k=n-1 ; k>=0 ; --k){       //从右端开始复制记录
        int j = A[k].keys[i];
        B[count[j]-1] = A[k];
        count[j]--;
    }
}

int main(){
    int a[10] = {11,55,32,57,48,63,12,177,24,10};
}
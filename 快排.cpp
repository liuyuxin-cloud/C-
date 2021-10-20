#include <iostream>
using namespace std;

//以数组为例，数组第一个元素用来保存枢轴数值
int Partition(int R[], int low, int high){
    R[0] = R[low];    //将最左边元素设置为枢轴
    int pivotkey = R[low];
    while(low < high){
        while(low < high && R[high] >= pivotkey){
            --high;
        }
        if(low < high){
            R[low++] = R[high];
        }
        while(low < high && R[low] <= pivotkey){
            ++low;
        }
        if(low < high){
            R[high--] = R[low];
        }
    }
    R[low] = R[0];
    return low; //返回枢轴位置
}

void QSort(int R[],int s, int t){
    if(s < t){
        int pivotloc = Partition(R,s,t);
        QSort(R,s,pivotloc-1);
        QSort(R,pivotloc+1,t);
    }
}

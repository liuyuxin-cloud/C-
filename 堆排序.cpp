#include <iostream>
using namespace std;

//创建堆
//由无序序列建成大顶堆的过程是“自下而上”进行筛选的过程
//数组有效元素下标从1开始，这样每一个叶结点的两个子节点下标分别为2n和2n+1

void HeapAdjust(int h[], int s, int m){
    int rc = h[s];
    for(int j = 2 * s; j <= m; j *= 2){
        if(j < m && h[j] < h[j+1])    ++j;
        if(rc >= h[j])      break;
        h[s] = h[j];
        s = j;
    }
    h[s] = rc;
}

void HeapSort(int h[], int len){
    for(int i = len / 2; i > 0; i--){ //从最后的非叶结点开始向上建成大顶堆
        HeapAdjust(h, i, len);
    }
    int w = h[1];  //将第一个元素与最后一个交换
    h[1] = h[len];
    h[len] = w;
    for(int i = len - 1; i > 1; i--){ //排序
        HeapAdjust(h, 1, i); //恢复大顶堆，有序区间为【i，len】
        int w = h[1];
        h[1] = h[i];
        h[i] = w;
    }
}
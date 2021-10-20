#include <iostream>
using namespace std;

//线性表的顺序存储表示
const int LIST_INIT_SIZE = 100;
const int LISTINCREMENT = 10;
typedef int ElemType;

typedef struct{
    ElemType *elem; //数组的头指针
    int length;
    int listsize;
    int incrementsize;
}SqList;

//初始化操作
void InitList_Sq(SqList &L,int maxsize=LIST_INIT_SIZE,int incresize = LISTINCREMENT){
    L.elem = new ElemType[maxsize];
    L.length = 0;
    L.listsize = maxsize;
    L.incrementsize = incresize;
}

//查找元素操作
int LocateElem_Sq(SqList L,ElemType e){
    int i=0;
    while(i < L.length && L.elem[i] != e)   i++;
    if(i == L.length) return -1;
    else return i;
}

//为顺序表追加空间
void increment(SqList &L){
    ElemType* a;
    a = new ElemType[L.listsize + L.incrementsize];
    for(int i=0 ; i<L.length ; i++){
        a[i] = L.elem[i];
    }
    delete[] L.elem;
    L.listsize += L.incrementsize;
}

//插入元素操作
void ListInsert_Sq(SqList &L,int i,ElemType e){
    if(i<0 || i>= L.length) ErrorMessage("i值不合法！");
    if(L.length >= L.listsize) increment(L);
    int p = L.elem[i-1];
    for(int q = L.elem[L.length-1] ; q >= p ; q--){
        L.elem[q+1] = L.elem[q];
    }
    L.elem[p] = e;
    L.length++;
}

//出错信息处理函数
void ErrorMessage(char* s){
    cout<< s << endl;
    exit(1);
}

//删除元素操作
void List_Delete_Sq(SqList &L,int i,ElemType e){
    if(i<0 || i>= L.length) ErrorMessage("i值不合法！");
    p = &(L.elem[i-1]);
    e = *p;
    q = L.elem + L.length-1;
    for(++p ; p<=q ; ++p){
        *(p-1) = *p;
    }
    L.length--;
}

//销毁结构操作
void DestroyList_Sq(SqList &L){
    delete[] L.elem;
    L.listsize = 0;
    L.length = 0;
}

/*
  其他算法
*/

//实现顺序表中前m个元素和后n个元素的互换
/*在不额外创建数组的情况下
将原数组逆置，再将前n个元素和后m个元素分别逆置
*/
void invert(ElemType &L[],int s,int t){
    //将数组下标从s到t的元素逆置
    for(int k=s ; k<=(s+t)/2 ; k++){
        int w = R[k];
        R[k] = R[t-k+s]  //t-(k-s)
        R[t-k+s] = w;
    }
}
void exchange1(SqList &L,int m,int n){
    invert(L.elem,0,m+n-1);
    invert(L.elem,0,n-1);
    invert(L.elem,n,n+m-1);
}

//从表中第m+1个元素起一次插入到元素0之前
void exchange2(SqList &L,int m,int n){
    for(int k=0 ; k<n ; k++){
        w = L.elem[m+k];
        for(int j = m+k ; j>k ; j--){
            L.elem[k] = w;
        }
    }
}

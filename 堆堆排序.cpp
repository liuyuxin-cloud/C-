#include<iostream>
using namespace std;




int main(){
    int a[10] = {1,5,8,7,6,9,4,3,2,0};
    HeapSort(a, 0, 10);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
}
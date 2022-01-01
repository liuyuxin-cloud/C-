#include<iostream>
#include<string>
#include"Stack.cpp"
using namespace std;

bool isPalindromeNumber(char* number){
    SqStack S;
    InitStack_Sq(S);
    int len = strlen(number);
    for(int i=0 ; i < len/2 ; i++){
        Push_Sq(S,number[i]);
    }
    for(int i=0 ; i < len/2 ; i++){
    	char ch;
		Pop_Sq(S,ch);
        if(ch != number[len/2+1+i])
            return false;
    }
    return true;
}

int main(){
    char number[100];
    cin >> number;
    cout << isPalindromeNumber(number);
}
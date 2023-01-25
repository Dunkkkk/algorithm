//
// Created by changgyo seo on 2023/01/25.
//
#include<iostream>
#include <stack>
using namespace std;
int number[500001];
string numberStr;
int numberSize;
int removeCapacity;

int atoi(char c){
    return c - '0';
}

void solve(){
    stack<int> s;
    s.push(number[0]);
    int i=1;
    for(;i<numberSize and removeCapacity > 0;i++) {
        while(!s.empty() and removeCapacity > 0 and s.top() < number[i]) {
            removeCapacity--;
            s.pop();
        }
        s.push(number[i]);
    }
    while(removeCapacity > 0) {
        s.pop();
        removeCapacity--;
    }
    stack<int> reverseS;
    while(!s.empty()) {
        reverseS.push(s.top());
        s.pop();
    }
    while(!reverseS.empty()){
        cout<<reverseS.top();
        reverseS.pop();
    }
    for(int j = i; j<numberSize;j++){
        cout<<number[j];
    }
}

int main(){
    cin>>numberSize>>removeCapacity;
    cin>>numberStr;
    for(int i=0;i<numberSize;i++) number[i] = atoi(numberStr[i]);
    solve();
}
#include<iostream>
#include <queue>
#include <utility>

using namespace std;
priority_queue<int> q;
int d,p,limit=1,ans = -1;


void input(){
    cin>>d>>p;
    while (d--) limit *= 10;
}

void sol(int tmp, int count,int maxim){
    if(count == 0 and tmp > ans){
        ans = tmp;
    } else if(count == 0) return;
    for(int i=9;i>=maxim;i--){
        if(tmp * i < limit){
            sol(tmp * i,count-1 ,i);
        }
    }
}



int main(){
    input();
    sol(1, p,2);
    cout<<ans;
}


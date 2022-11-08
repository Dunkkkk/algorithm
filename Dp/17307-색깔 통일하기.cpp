#include <iostream>
#define MAX 9223372036854775807

using namespace std;
int n,c;
int buttons[500000];
long long leftCount[500000];
long long rightCount[500000];
long long minCount = MAX;
int idx = 50000000;

void input(){
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>buttons[i];
    }
    for(int i=2;i<=n;i++){
        rightCount[i] = buttons[i] > buttons[i-1] ? c - buttons[i] + buttons[i-1] : buttons[i-1] - buttons[i];
        rightCount[i] += rightCount[i-1];
    }
    for(int i=n-1;i>=1;i--){
        leftCount[i] = buttons[i] > buttons[i+1] ? c - buttons[i] + buttons[i+1] : buttons[i+1] - buttons[i];
        leftCount[i] += leftCount[i+1];
    }
}

void solve(){
    
    for(int i=1;i<=n;i++){
        if(minCount > max(leftCount[i], rightCount[i])){
            minCount = max(leftCount[i], rightCount[i]);
            idx = i;
        }
    }
}

int main(){
    input();
    solve();
    cout<<idx<<"\n"<<minCount;
}

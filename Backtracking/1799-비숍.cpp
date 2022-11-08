
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
int check[12][12];
int board[12][12];
int checktwo[21];
int m;
int answer = 0;
vector<pair<int, int>> v;

void input(){
    cin>>m;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            int a;
            cin>>a;
            check[i][j]=1;
            if(a) {
                v.push_back({i,j});
            }
        }
    }
    for(int i=0;i<m+m;i++){
        checktwo[i] = 1;
    }
}

bool can(int i,int j){
    if (!checktwo[i+j]){
        return false;
    }
    if(i>j){
        i=i-j;
        j=0;
    }
    else {
        j = j-i;
        i=0;
    }
    return check[i][j];
}

void putFalse(int i,int j){
    checktwo[i+j] = 0;
    if(i>j){
        i=i-j;
        j=0;
    }
    else {
        j = j-i;
        i=0;
    }
    check[i][j]  = 0;
}

void putTrue(int i,int j ){
    checktwo[i+j] = 1;
    if(i>j){
        i=i-j;
        j=0;
    }
    else {
        j = j-i;
        i=0;
    }
    check[i][j]  = 1;
}

void solve(int idx, int maxi){
    int i = v[idx].first;
    int j = v[idx].second;
    if ( idx+1 == v.size()) {
        //cout<<"-----------------\n";
        if (can(i, j)) answer = max( answer, maxi+1);
        else answer = max(answer, maxi);
        return;
    }
    if (can(i, j)){
        //out<<i<<" "<<j<<endl;
        putFalse(i, j);
        solve(idx+1,maxi+1);
        putTrue(i, j);
        solve(idx+1,maxi);
    }
    else {
        solve(idx+1, maxi);
    }
}

int main() {
    input();
    solve(0,0);
    cout<<answer;
}

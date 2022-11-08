#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n,s;
vector<pair<int, int>> p;
int cache[301][3001];

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}


void input(){
    cin>>n>>s;
    p.push_back({0,0});
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        p.push_back({a,b});
    }
    sort(p.begin(), p.end(), comp);
}


int dp(int x,int recent){
    int& ret = cache[x][recent];
    if(ret != 0 ) return ret;
    ret = max(dp(x+1, recent), ret);
    if( p[recent].first + s <= p[x].first ) ret = max(dp(x+1, x) + p[x].second, ret);
    return ret;
}

int main(){
    input();
    dp(0,0);
}


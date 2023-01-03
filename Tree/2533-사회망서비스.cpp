//
// Created by changgyo seo on 2022/12/24.
//
#include<iostream>
#include<vector>
#define MAX 2147483647

using namespace std;

int cache[1000001][2];
bool visit[1000001][2];
vector<int> tree[1000001];

int solve(int node, int isEarly){
    cout<<node<<" "<<isEarly<<endl;
    if(tree[node].size() == 1) return isEarly ? 1 : 0;

    int& ret = cache[node][isEarly];
    if(ret != MAX) return ret;

    int answer = 0;
    for(int next : tree[node]) {
        if(!visit[next][isEarly]) {
            visit[next][isEarly] = true;
            if(isEarly) answer += min(solve(next, 0) , solve(next, 1));
            else answer += solve(next, 1);
        }
    }
    ret = isEarly ? answer + 1 : answer;
    cout<<node<<" "<<isEarly<<" "<<ret<<endl;
    return ret;
}



int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        cache[a][0] = MAX;
        cache[b][0] = MAX;
        cache[a][1] = MAX;
        cache[b][1] = MAX;
    }
    visit[1][0] = true;
    visit[1][1] = true;
   // solve(1,0);
    solve(1,1);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<cache[i][0]<<" "<<cache[i][1]<<endl;
    }
    cout<<min(cache[1][0], cache[1][1]);
}
//
// Created by changgyo seo on 2022/12/26.
//
#include<iostream>
#include<stack>
#include<utility>
#include<vector>

using namespace std;

int tier[1000001];
int parent[1000001];
bool visit[1000001];
int n,m,q;
pair<int, int> road[100001];
stack<int> removeOrder;

int findParent(int a){
    if(parent[a] == a) return a;

    return parent[a] = findParent(parent[a]);
}

void uni(int a, int b){
    int u = findParent(a);
    int v = findParent(b);

    if(u == v)  return;

    if( tier[u] > tier[v] ) {
        parent[u] = v;
        tier[v] += tier[u];
    }
    else {
        parent[v] = u;
        tier[u] += tier[v];
    }
}


int main(){
    cin>>n>>m>>q;

    for(int i=1;i<=n;i++){
        tier[i] = 1;
        parent[i] = i;
    }
    uni(n,m);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        road[i] = {a,b};
    }
    for(int i=1;i<=q;i++){
        int a;
        cin>>a;
        visit[a] = true;
        removeOrder.push(a);
    }
    for(int i=1;i<=m;i++) if(!visit[i]) uni(road[i].first, road[i].second);
    int answer = 0;
    while(!removeOrder.empty()){
        int index = removeOrder.top();
        removeOrder.pop();
        int a = road[index].first;
        int b = road[index].second;

        // cout<<a<<" "<<findParent(a)<<" "<<b<<" "<<findParent(b)<<"\n";
        if(findParent(a) != findParent(b)) {
            answer += tier[findParent(a)] * tier[findParent(b)];
            uni(a,b);
        }


    }
    cout<<answer;

    return 0;
}
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#define INF 2147483647;

using namespace std;
int island[301][301];
vector<vector<int>> l;
int h;
int n;
int k=1;
int dirx[4] = {0,0,-1,1};
int diry[4] = {-1,1,0,0};
int parent[301];
int soon[301];
int ans[301][301];


bool issize(int y, int x){
    return x>=0 and x<n and y>=0 and y<n;
}

int find(int x){
    if(parent[x] == x) return  x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    int a = find(x);
    int b = find(y);
    
    if(a==b) return;
    if (soon[a] < soon[b]){
        int temp = a;
        a = b;
        b = temp;
    }
    parent[b] = a;
    if(soon[a]==soon[b]) soon[a]++;
}

void dfs(int y,int x,int num){
    island[y][x] = num;
    for(int i=0;i<4;i++){
        int ny = y+ diry[i];
        int nx = x+ dirx[i];
        if(issize(ny, nx)){
            if(abs(l[ny][nx] - l[y][x]) <= h and island[ny][nx] == 0) dfs(ny,nx,num);
        }
    }
}

void makeIsland(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(island[i][j] == 0){
                dfs(i,j,k);
                k++;
            }
        }
    }
    for(int i=1;i<=k;i++){
        parent[i] = i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j] = INF;
        }
    }
}

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.first < b.first;
}

int solve(){
    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                int ny=i+diry[k];
                int nx=j+dirx[k];
                if(issize(ny, nx)){
                    if(island[i][j] != island[ny][nx]){
                        if(ans[island[i][j]][island[ny][nx]] > abs(l[ny][nx] - l[i][j])){
                            ans[island[i][j]][island[ny][nx]] = abs(l[ny][nx] - l[i][j]);
                            ans[island[ny][nx]][island[i][j]] = abs(l[ny][nx] - l[i][j]);
                        }
                    }
                }
            }
        }
    }
    vector<pair<int, pair<int, int>>> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ans[i][j] != 2147483647) v.push_back({ans[i][j],{i,j}});
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        if(find(v[i].second.first)!=find(v[i].second.second)) {
            merge(v[i].second.first, v[i].second.second);
            answer += v[i].first;
        }
    }
    return answer;
}



int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    l = land;
    h = height;
    n = land.size();
    makeIsland();
    answer = solve();
    return answer;
}

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 2147483646;

using namespace std;
int dirx[4]={0,0,-1,1};
int diry[4]={-1,1,0,0};
vector<string> g;
int dis;
int maxy;
int maxx;
int ans = INF;

bool issize(int y, int x){
    return x >= 0 and x < maxx and y>=0 and y<maxy;
}

queue<pair<pair<int,int>>> q;
bool visit[51][51];

void bfs(){
    q.push({{0,0},{0,0}});
    visit[0][0] = true;
    while(!q.empty()){
        pair<pair<int,int>> cur = q.front();
        q.pop();
        if(cur.second.first > dis) continue;
        visit[cur.first.first][cur.first.second] = true;
        if(cur.first.first == maxy-1 and cur.first.second == maxx-1) ans = min(ans, cur.second.second);
        for(int i=0;i<4;i++){
            int ny = cur.first.first+diry[i];
            int nx = cur.first.second+dirx[i];
            if(issize(ny,nx)){
                if(g[ny][nx] != '#' and !visit[ny][nx]){
                    if(cur.second.first < dis)q.push({{ny,nx},{cur.second.first+1,cur.second.second}});
                    if(g[cur.first.first][cur.first.second] != 'F') q.push({{ny,nx},{1,cur.second.second+1}});
                }
            }
        }
    }
}

int solution(vector<string> grid, int k) {
    int answer = -1;
    g = grid;
    dis = k;
    maxy = grid.size();
    maxx = grid[0].size();
    bfs();
    answer = ans;
    return answer;
}


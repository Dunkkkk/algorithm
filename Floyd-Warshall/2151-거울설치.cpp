//
// Created by changgyo seo on 2023/01/16.
//
#include <iostream>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define MAX 300

using namespace std;
int n;
string map[51];
bool visit[51][51][251];
int dirY[4] = {-1,1,0,0};
int dirX[4] = {0,0,-1,1};
pii one = {-1,-1};
pii two;

bool isSize(int y, int x) {
    return x >= 0 and x < n and y >= 0 and y < n;
}
// 0 up 1 down 2 left 3 right 4 all
int bfs(){
   priority_queue<pair<pii,pii>, vector<pair<pii,pii>>, greater<pair<pii,pii>>> q;
   q.push({{0,4},one});
   visit[one.first][one.second][0] = true;


    while (!q.empty()){
        pair<pii,pii> f = q.top();
        q.pop();

        cout<<f.second.first <<" "<<f.second.second<<" "<<f.first.second<<" "<<f.first.first<<"\n";
        if(f.second == two) return f.first.first;
        if(map[f.second.first][f.second.second] == '.' and f.first.second != 4) {
            int ny = dirY[f.first.second] + f.second.first;
            int nx = dirX[f.first.second] + f.second.second;
            if(isSize(ny,nx) and !visit[ny][nx][f.first.first] and map[ny][nx] != '*'){
                visit[ny][nx][f.first.first] = true;
                q.push({{f.first.first, f.first.second},{ny,nx}});
            }
        }
        else if(map[f.second.first][f.second.second] == '!' or f.first.second == 4) {
            if(f.first.second == 4) {
                for (int i = 0; i < 4; i++) {
                    int ny = dirY[i] + f.second.first;
                    int nx = dirX[i] + f.second.second;
                    if(isSize(ny,nx) and !visit[ny][nx][f.first.first] and map[ny][nx] != '*'){
                        visit[ny][nx][f.first.first] = true;
                        q.push({{f.first.first, i},{ny,nx}});
                    }
                }
            }
            else{
                if(f.first.second < 2) {
                    for (int i = 2; i < 4; i++) {
                        int ny = dirY[i] + f.second.first;
                        int nx = dirX[i] + f.second.second;
                        if(isSize(ny,nx) and !visit[ny][nx][f.first.first+1] and map[ny][nx] != '*'){
                            visit[ny][nx][f.first.first+1] = true;
                            q.push({{f.first.first + 1, i},{ny,nx}});
                        }
                    }
                    int ny = dirY[f.first.second] + f.second.first;
                    int nx = dirX[f.first.second] + f.second.second;
                    if(isSize(ny,nx) and !visit[ny][nx][f.first.first] and map[ny][nx] != '*'){
                        cout<<f.second.first <<" "<<f.second.second<<" "<<f.first.second<<" "<<f.first.first<<"\n";
                        visit[ny][nx][f.first.first] = true;
                        q.push({{f.first.first, f.first.second},{ny,nx}});
                    }
                }
                else {
                    for (int i = 0; i < 2; i++) {
                        int ny = dirY[i] + f.second.first;
                        int nx = dirX[i] + f.second.second;
                        if(isSize(ny,nx) and !visit[ny][nx][f.first.first + 1] and map[ny][nx] != '#'){
                            visit[ny][nx][f.first.first + 1] = true;
                            q.push({{f.first.first + 1, i},{ny,nx}});
                        }
                    }
                    int ny = dirY[f.first.second] + f.second.first;
                    int nx = dirX[f.first.second] + f.second.second;
                    if(isSize(ny,nx) and !visit[ny][nx][f.first.first] and map[ny][nx] != '*'){
                        visit[ny][nx][f.first.first] = true;
                        q.push({{f.first.first, f.first.second},{ny,nx}});
                    }
                }
            }
        }
    }
    return 300;
}

int main() {
    cin>>n;

    for(int i=0;i<n;i++) {
        string temp;
        cin>>temp;
        map[i] = temp;
        for(int j=0;j<n;j++){
            if(map[i][j] == '#' and one.first == -1) one = {i,j};
            else if(map[i][j] == '#') two = {i,j};
        }
    }
    cout<<bfs();
}
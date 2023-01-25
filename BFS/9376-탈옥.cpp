//
// Created by changgyo seo on 2023/01/12.
//
#include<iostream>
#include <utility>
#include <queue>
#define pii pair<int,pair<int ,int>>


using namespace std;
int n,m;
string map[101];
int dirY[4] = {-1,1,0,0};
int dirX[4] = {0,0,-1,1};
int dist[101][101];
int dist2[101][101];
pair<int,int> one = {-1,-1};
pair<int,int> two;

bool isSize(int y, int x){
    return x>=0 and x<m and y>=0 and y<m;
}
bool isFinish(int y, int x){
    return x==0 or x == m-1 or y ==0 or y == n-1;
}

int bfs(){
    priority_queue<pii> fpq;
    fpq.push({0,one});
    dist[one.first][one.second] = 0;

    while(!fpq.empty()){
        pii f = fpq.top();
        fpq.pop();
        dist[f.second.first][f.second.second] = f.first;
        for(int i=0;i<4;i++){
            int ny = f.second.first + dirY[i];
            int nx = f.second.second + dirX[i];
            if(isSize(ny,nx) and dist[ny][nx] == -1 and map[ny][nx] != '*'){

                if(map[ny][nx] == '#'){
                    fpq.push({f.first,{ny,nx}});
                }
                else {
                    fpq.push({f.first + 1,{ny,nx}});
                }
            }
        }
    }
    queue<pii> q;
    q.push({0,two});
    dist2[two.first][two.second];
    while(!q.empty()){
        pii f = q.front();
        q.pop();
        dist2[f.second.first][f.second.second] = f.first;
        for(int i=0;i<4;i++){
            int ny = f.second.first + dirY[i];
            int nx = f.second.second + dirX[i];
            if(isSize(ny,nx) and dist2[ny][nx] == -1 and map[ny][nx] != '*'){
                if(dist[f.second.first][f.second.second] - dist[ny][nx] > 0){
                    q.push({f.first + 1,{ny,nx}});
                }
                else {
                    q.push({f.first,{ny,nx}});
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(dist[i][j] == -1) cout<<"a ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------------------\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(dist2[i][j] == -1) cout<<"a ";
            else cout<<dist2[i][j]<<" ";
        }
        cout<<endl;
    }
    int answer = 2147483647;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(isFinish(i,j) and dist[i][j] != -1 and dist2[i][j] != -1) answer = answer > dist[i][j] + dist2[i][j] ? dist[i][j] + dist2[i][j] : answer;
        }
    }

    return answer -1;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
       cin>>n>>m;
       for(int i=0;i<n;i++) {
           string temp;
           cin>>temp;
           map[i] = temp;
           for (int j = 0; j < m; j++) {
               dist[i][j] = -1;
               dist2[i][j] = -1;
               if (map[i][j] == '$') {
                   if (one.first == -1) one = {i, j};
                   else two = {i, j};

               }
           }
       }

       cout<<bfs()<<"\n";
    }
}
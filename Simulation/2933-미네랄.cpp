//
// Created by changgyo seo on 2023/01/10.
//
#include<iostream>
#include<queue>
#include <utility>
#define pii pair<int,int>

using namespace std;

char map[120][120];
int n,m,k;
bool visit[120][120];
int dirY[4] = {1,0,0,-1};
int dirX[4] = {0,-1,1,0};

bool isSize(int y, int x){
    return x >= 0 and x < m and y>=0 and y <= n;
}

void display(){
    for(int i=n;i>=1;i--) {
        for(int j=m-1;j>=0;j--) {
            cout<<map[i][j];
        }
        cout<<endl;
    }
}

void clearVisit() {
    for(int i=0;i<=n;i++) {
        for(int j=0;j<m;j++) {
            visit[i][j] = false;
        }
    }
}

void dfs(){
    queue<pii> q;
    q.push({0,0});
    visit[0][0] = true;

    while(!q.empty()){
        pii f = q.front();
        q.pop();

        for(int i=0;i<4;i++){
           int ny = f.first + dirY[i];
           int nx = f.second + dirX[i];
           if(isSize(ny,nx) and !visit[ny][nx] and map[ny][nx] == 'x') {
               visit[ny][nx] = true;
               q.push({ny,nx});
           }
        }
    }
}

//dir == 0 left, dir == 1 right
void changeMap(int h, int dir){
    if(dir == 0){
        for(int i=m-1;i>=0;i--) {
            if(map[h][i] == 'x') {
                map[h][i] = '.';
                break;
            }
        }
    }
    else{
        for(int i=0; i<m;i++) {
            if(map[h][i] == 'x') {
                map[h][i] = '.';
                break;
            }
        }
    } // n

    clearVisit(); // n * n
    dfs(); // n * n
    int dropHeight = 2147483647;
    for(int i=0;i<m;i++){
        int recentHeight = 0;
        bool isDrop = false;
        for(int j=1;j<=n;j++){
            if(!visit[j][i] and map[j][i] == 'x') {recentHeight = j - recentHeight; isDrop = true; break; }
            else if(map[j][i] == 'x') recentHeight = j;
        }
        if(isDrop) dropHeight = dropHeight > recentHeight ? recentHeight : dropHeight;
    } // n * n
    dropHeight = dropHeight == 2147483647 ? 0 : dropHeight - 1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<m;j++){
            if(!visit[i][j] and map[i][j] == 'x') {

                map[i][j] = '.';
                map[i-dropHeight][j] = 'x';
            }
        }
    } // n * n
}

int main(){
    cin>>n>>m;
    for(int i=n;i>=1;i--) {
        for(int j=m-1;j>=0;j--) {
            cin>>map[i][j];
        }
    }
    for(int i=0;i<m;i++){
        map[0][i] = 'x';
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        changeMap(temp, i % 2);
    }
    display();
}

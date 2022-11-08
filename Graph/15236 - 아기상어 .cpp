#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;
int n;
int arr[21][21];
pair<int, int> shark;
pair<int, int> canGo;
int sharkLevel = 2;
int second = 0;
int sharksNeed = 2;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
bool visit[21][21];

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if (arr[i][j] == 9) {
                shark = {i,j};
                arr[i][j] = 0;
            }
        }
    }
}

bool isSize(int y,int x){
    return x>=0 and x< n and y>=0 and y<n;
}

pair<int, int> nearGo(){
    queue<pair<int, int>> q;
    q.push(shark);
    visit[shark.first][shark.second] = true;
    pair<int, int> now;
    while(!q.empty()){
        now = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nY = now.first + diry[i];
            int nX = now.second + dirx[i];
            if(isSize(nY,nX)){
                if(arr[nY][nX] < sharkLevel and arr[nY][nX] != 0){
                    now = {nX,nY};
                    break;
                }
                else if (arr[nY][nX] == sharkLevel or arr[nY][nX] == 0) {
                    if(!visit[nY][nX]){
                        visit[nY][nX] = true;
                        q.push({nY,nX});
                    }
                }
            }
        }
    }
    if(arr[now.first][now.second] < sharkLevel) return now;
    return {-1,-1};
}

int Go(){
    int min = 100;
    pair<int,int> goThere;
    goThere = nearGo();
    arr[goThere.first][goThere.second] = 0;
    min = abs(goThere.first - shark.first) + abs(goThere.second - shark.second);
    shark = goThere;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visit[i][j] = false;
        }
    }
    return min;
}

void sol(){
    int addTime;
    do{
        addTime = Go();
        second += addTime;
        sharksNeed--;
        if (sharksNeed == 0){
            sharkLevel++;
            sharksNeed = sharkLevel;
        }
    }while(addTime != 100);
    
    cout<<second - 100;
}

int main(){
    input();
    sol();
}

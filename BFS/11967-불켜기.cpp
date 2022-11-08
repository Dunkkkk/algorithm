#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int idx[102][102]; // 위치 를 인덱스로
vector<pair<int,int>> board[10002]; //어디에서 어디 불이켜지나
int n,m, number = 1, answer;
bool turnOn[102][102]; // 이곳에 불이 켜져있나?
bool visit[102][102]; // 이곳에 온적이 있나?
int dirx[4] = {0,0,-1,1};
int diry[4] = {-1,1,0,0};
int newBoard[102][102];

void input(){
    cin>>n>>m;
    idx[1][1] = number++;

    for(int i=0;i<m;i++){

        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(idx[a][b] == 0) idx[a][b] = number++;
        if(idx[c][d] == 0) idx[c][d] = number++;

        board[idx[a][b]].push_back({c,d});
    }
}

bool isSize(int x, int y){
    return x>=1 and x<=n and y>=1 and y<=n;
}

bool checkLight(int x, int y){
    for(int i=0;i<4;i++){
        int nx = x + dirx[i];
        int ny = y + diry[i];
        if(isSize(nx,ny) and visit[nx][ny]) return true;
    }
    return false;
}

void bfs(){

    queue<pair<int,int>> q;
    q.push({1,1});
    visit[1][1] = true;
    turnOn[1][1] = true;

    while(!q.empty()){
       pair<int,int> f = q.front();
       q.pop();

       int currentIndex = idx[f.first][f.second];
       for(int i=0;i<board[currentIndex].size(); i++){
           int nx = board[currentIndex][i].first;
           int ny = board[currentIndex][i].second;
           turnOn[nx][ny] = true;
           if(!visit[nx][ny] and checkLight(nx,ny)){
               q.push({nx,ny});
               visit[nx][ny] = true;
           }
       }

       for(int i=0;i<4;i++){
           int nx = f.first + dirx[i];
           int ny = f.second + diry[i];
           if(isSize(nx,ny) and turnOn[nx][ny] and !visit[nx][ny]){
               q.push({nx,ny});
               visit[nx][ny] = true;
           }
       }
    }
}
int solve(){
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(turnOn[i][j]) ans++;
        }
    }
    return ans;
}

int main() {
    input();
    bfs();

    cout<<solve();
}
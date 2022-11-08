#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct location {
    int y;
    int x;
};

vector<pair<location, location>> target;
vector<int> len;
int n,m,fuel;
int board[100][100];
location taxi;

void input(){
    cin>>n>>m>>fuel;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>board[i][j];
        }
    }
    int a,b;
    cin>>a>>b;
    taxi = {a,b};
    for(int i=0;i<m;i++){
        int c,d;
        cin>>a>>b>>c>>d;
        target.push_back({{a,b},{c,d}});
        board[a][b] = 10 + target.size() - 1;
    }
}
bool visit[100][100];
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};

bool isSize(int y, int x){
    return x>=1 and x<=n and y>=1 and y<=n;
}

int bfs(int idx, int y, int x){
    queue<pair<location,int>> q;
    q.push({{y,x},0});
    visit[y][x] = true;
    while(!q.empty()) {
        pair<location,int> f = q.front();
        q.pop();
        if(target[idx].second.y == f.first.y and target[idx].second.x == f.first.x) {
            len.push_back(f.second);
            return f.second;
        }
        for(int i=0;i<4;i++){
            int nx = f.first.x + dirx[i];
            int ny = f.first.y + diry[i];
            if(isSize(ny, nx) and !visit[ny][nx] and board[ny][nx] != 1){
                visit[ny][nx] = true;
                q.push({{ny,nx},f.second+1});
            }
        }
    }
    return 1;
}
int idx = 0;

int humanbfs(int y, int x){
    queue<pair<location,int>> q;
    q.push({{y,x},0});
    visit[y][x] = true;
    if (board[y][x] >= 10){
        idx = board[y][x] - 10;
        board[y][x] = 0;
        return 0;
    }
    location ans = {10000,10000};
    int dis = 100000;
    while(!q.empty()) {
        pair<location,int> f = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = f.first.x + dirx[i];
            int ny = f.first.y + diry[i];
            if(isSize(ny, nx) and !visit[ny][nx] and board[ny][nx] != 1){
                if (board[ny][nx] >= 10) {
                    if((ans.y > ny or (ans.y == ny and ans.x > nx)) and dis >= f.second){
                        ans = {ny,nx};
                        dis = f.second + 1;
                        idx = board[ny][nx] - 10;
                    }
                }
                visit[ny][nx] = true;
                q.push({{ny,nx},f.second+1});
            }
        }
    }
    board[ans.y][ans.x] -= 10;
    return dis;
}

void checkDis(){
    for(int i=0;i<target.size();i++){
        bfs(i,target[i].first.y, target[i].first.x);
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=n;k++) {
                visit[j][k] = false;
            }
        }
    }
    
}


int main(){
    input();
    checkDis();
    bool check = false;
    for(int i=0; i<target.size() ;i++){
        //cout<<fuel<<" ";
        int temp = humanbfs(taxi.y, taxi.x);
        //cout<<temp<<" "<<len[idx]<<endl;
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=n;k++) {
                visit[j][k] = false;
            }
        }
        if( fuel < temp or len.size() != target.size() or fuel - temp <= len[idx]) {
            check = true;
            break;
        }
        else {
            fuel -= temp;
            fuel += (len[idx]);
            taxi = target[idx].second;
        }
        
    }
    if(check) cout<<-1;
    else cout<<fuel;
}

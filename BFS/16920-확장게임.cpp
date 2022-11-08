#include<iostream>
#include<queue>
#include <utility>
#define MAX 2147483647

using namespace std;
struct location{
    int y;
    int x;
};
struct qData {
    location loc;
    int person;
    int turn;
    int life;
};
int diry[4] = {-1,1,0,0};
int dirx[4] = {0,0,-1,1};
int n,m,p;
location person_l[10];


int person[10];
pair<int, int> visit[1001][1001];
char board[1001][1001];

void input(){
    cin>>n>>m>>p;
    for(int i=0;i<p;i++) cin>>person[i];
    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = {10, MAX};
            cin >> board[i][j];
            if (board[i][j] != '.' and board[i][j] != '#') {
                visit[i][j] = {board[i][j] - '0', 0};
                person_l[board[i][j] - '0'] = {i, j};
            }
        }
    }
}

bool isSize(int y, int x){
    return x>= 0 and x < m and y>=0 and y<n;
}

int bfs(){
    int answer[10];
    queue<qData> q;
    for(int i=1;i<=p;i++){
        q.push({{person_l[i].y,person_l[i].x}, i, 0, person[i]});
    }

    while(!q.empty()){
        qData f = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny = f.loc.y + diry[i];
            int nx = f.loc.x + dirx[i];
            if(isSize(ny,nx) and (board[ny][nx] != '#') and ((visit[ny][nx].second > f.turn) or (visit[ny][nx].second == f.turn and visit[ny][nx].first > f.person))){
                visit[ny][nx] = {f.person, f.turn};
                int t = f.life - 1 < 0 ? f.turn + 1 : f.turn;
                int l = f.life - 1 < 0 ? person[f.person] - 1: f.life - 1;
                q.push({{ny,nx}, f.person, t, l});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //if (visit[i][j].first != 10) answer[visit[i][j].first]++;
            cout<<visit[i][j].first <<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=p;i++){
        cout<<answer[i]<<" ";
    }
}

int main(){
   input();
   bfs();
}
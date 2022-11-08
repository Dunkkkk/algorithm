#include <iostream>
#include <queue>

using namespace std;
struct location {
    int y;
    int x;
    int turn;
};
int n,m;
int board[51][51];
bool visit[51][51];
int answer;

location next(location loc, int number, int i){
    switch (i) {
        case 0:
            return {loc.y - number , loc.x, loc.turn};
        case 1:
            return  {loc.y+number, loc.x, loc.turn};
        case 2:
            return {loc.y, loc.x - number, loc.turn};
        case 3:
            return {loc.y, loc.x + number, loc.turn};
        default:
            return {0,0};
    }
    return {0,0};
}

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            board[i][j] = temp[j] - '0';
        }
    }
}

bool isSize(int y, int x){
    return x>=0 and x<m and y>=0 and y<n;
}

void solve(){
    queue<location> q;
    q.push({0,0,0});
    visit[0][0] = true;

    while(!q.empty()){
        location f = q.front();
        cout << f.y<<" "<<f.x << endl;
        answer = f.turn + 1;
        q.pop();
        for(int i=0;i<4;i++){
            location nl = next(f,board[f.y][f.x], i);

            if(isSize(nl.y,nl.x) and !visit[nl.y][nl.x] and board[nl.y][nl.x] != 'H' - '0') {
                //cout<<nl.y<<" "<<nl.x<<endl;
                visit[nl.y][nl.x] = true;
                q.push({nl.y, nl.x, nl.turn + 1});
            } else if(isSize(nl.y,nl.x) and visit[nl.y][nl.x]){
                answer = -1;
                while(!q.empty()) q.pop();
                break;
            }
        }
    }
}

int main(){
    input();
    solve();
    cout<<answer;
}
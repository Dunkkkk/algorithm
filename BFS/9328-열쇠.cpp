#include <iostream>
#include <queue>
#include <utility>


using namespace std;
string board[101];
queue<pair<int,int>> q;
queue<pair<int,int>> door[27];
bool visit[101][101];
int diry[4] = {-1,1,0,0};
int dirx[4] = {0,0,-1,1};
bool key[27];
int n,m;

bool isSize(int y, int x){
    return x>=0 and x<m and y>=0 and y<n;
}

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        board[i] = temp;
        for(int j=0;j<m;j++){
            if((i ==0 or j == 0 or i == n-1 or j == m-1) and (board[i][j] == '.' or (board[i][j] >= 'a' and board[i][j] <= 'z'))){
                visit[i][j] = true;
                q.push({i,j});
            }
        }
    }
    string temp;
    cin>>temp;
    for(int i=0;i<temp.size();i++){
        key[temp[i]-'a'] = true;
    }
}

int solve(){
    int answer = 0;
    while(!q.empty()){
        pair<int, int> f = q.front();
        //cout<<f.first<<" "<<f.second<<" "<<board[f.first][f.second]<<endl;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = f.first + diry[i];
            int nx = f.second + dirx[i];
            if(isSize(ny,nx) and !visit[ny][nx] and board[ny][nx] != '*'){
                if(board[ny][nx] == '.') {
                    visit[ny][nx] = true;
                    q.push({ny,nx});
                }
                else if(board[ny][nx] == '$'){
                    visit[ny][nx] = true;
                    answer++;
                    q.push({ny,nx});
                }
                else if(board[ny][nx] >= 'A' and board[ny][nx] <= 'Z' and key[board[ny][nx] - 'A']) {
                    visit[ny][nx] = true;
                    q.push({ny,nx});
                }
                else if(board[ny][nx] >= 'A' and board[ny][nx] <= 'Z') {
                    door[board[ny][nx] - 'A'].push({ny,nx});
                }
                else if(board[ny][nx] >= 'a' and board[ny][nx] <= 'z'){
                    q.push({ny,nx});
                    visit[ny][nx] = true;
                    while(!door[board[ny][nx] - 'a'].empty()) {

                        visit[door[board[ny][nx] - 'a'].front().first][door[board[ny][nx] - 'a'].front().second] = true;
                        q.push(door[board[ny][nx] - 'a'].front());
                        door[board[ny][nx] - 'a'].pop();
                    }
                    key[board[ny][nx] - 'a'] = true;
                }
            }
        }
    }
    return answer;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--) {
        input();
        cout << solve()<<"\n";
        for(int i=0;i<27;i++){
            key[i] = false;
            while(!door[i].empty()) door[i].pop();
        }
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                visit[i][j] = false;
            }
        }
    }
    return 0;
}
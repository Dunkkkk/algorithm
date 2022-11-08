#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
struct location {
    int y;
    int x;
};

int diry[4] = {-1,1,0,0};
int dirx[4] = {0,0,-1,1};
queue<pair<location, int>> q;
vector<location> persons;

bool isSize(int y, int x){
    return x>=0 and y>=0 and x<5 and y<5;
}


int bfs(vector<string> list){
    
    vector<location> persons;
    queue<pair<location, int>> q;
    bool visit[5][5];
    
    for(int i=0;i<list.size();i++){
        for(int j=0;j < list[i].size();j++){
            if(list[i][j] == 'P') q.push({{i,j}, 0});
        }
    }
    
    while (!q.empty()) {
        pair<location, int> f = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny = f.first.y + diry[i];
            int nx = f.first.x + dirx[i];
            if(isSize(ny,nx) and list[ny][nx] != 'X' and !visit[ny][nx]){
                if(f.second + 1 < 2 and list[ny][nx] == 'P') return false;
                visit[ny][nx] = true;
                q.push({{ny,nx}, f.second + 1});
            }
        }
    }
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(vector<string> v : places){
        
    }
    
    
    
    return answer;
}

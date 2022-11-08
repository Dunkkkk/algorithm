#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

vector<int> e[20001];
queue<pair<int, int>>  q;
bool visit[200001];
int length[20001];

int bfs(){
    int max = 0;
    visit[1] = true;
    for(int i=0;i<e[1].size();i++){
        visit[e[1][i]] = true;
        q.push({e[1][i],1});
    }
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        //cout<<cur.first<<" "<<cur.second<<"\n";
        length[cur.second]++;
        if (cur.second > max) max = cur.second;
        for(int i=0;i<e[cur.first].size();i++){
            if(!visit[e[cur.first][i]]){
                visit[e[cur.first][i]] = true;
                q.push({e[cur.first][i],cur.second+1});
            }
        }
    }
    return max;
}

void make(vector<vector<int>> tmp){
    for(int i=0;i<tmp.size();i++){
        e[tmp[i][0]].push_back(tmp[i][1]);
        e[tmp[i][1]].push_back(tmp[i][0]);
    }
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    make(edge);
    answer = length[bfs()];
    return answer;
}

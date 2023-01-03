//
// Created by changgyo seo on 2022/12/26.
//
#include <string>
#include<queue>
#include <vector>
#include <utility>

using namespace std;

vector<int> nodes[100001];
int dist[100001];
bool visit[100001];

void findDist(int index, int n){
    queue<pair<int,int>> q;
    q.push({index, 0});
    visit[index] = true;

    while(!q.empty()){
        pair<int,int> f = q.front();
        q.pop();
        dist[f.first] = f.second;
        for(int i=0;i<nodes[f.first].size();i++) {
            int temp = nodes[f.first][i];

            if(!visit[temp]) {
                visit[temp] = true;
                q.push({temp, f.second + 1});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for(int i=1;i<=n;i++){
        dist[i] = -1;
    }
    for(int i=0;i<roads.size();i++){
        int a = roads[i][0];
        int b = roads[i][1];
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    findDist(destination, 0);
    for(int elem : sources) answer.push_back(dist[elem]);


    return answer;
}
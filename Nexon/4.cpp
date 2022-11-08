#include <iostream>
#include <vector>
#include <utility>
using namespace  std;
#define MAX 987654321

vector <pair<int,int>> adj[MAX]; // 노드들의 정보들을 담는 벡터
int dist[MAX]; //최단거리를 저장하는 배열
int V,E;

void dijkstra(int node){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,node));
    while(!pq.empty()){
        node = pq.top().second;
        pq.pop();
        for(int i = 0;i<adj[node].size();i++){
            int next_node = adj[node][i].first;
            int new_val = adj[node][i].second + dist[node];
            int before_val = dist[next_node];
            if(new_val < before_val){
                dist[next_node] = new_val;
                pq.push(make_pair(-1*new_val,next_node));
            }
        }
    }
}


int minCostPath(int g_nodes, int g_edges, int* g_from, int* g_to, int* g_weight, int x, int y) {
    for(int i = 0;i<g_edges;i++){
        adj[g_to[i]].push_back(make_pair(g_from[i],g_weight[i]));
        adj[g_from[i]].push_back(make_pair(g_to[i],g_weight[i]));
    }
    dist[1] = 0; //시작점 초기화
    for(int i = 1;i<=g_nodes;i++) dist[i] = MAX;
    dijkstra(1);
    int ans = dist[x];
    
}



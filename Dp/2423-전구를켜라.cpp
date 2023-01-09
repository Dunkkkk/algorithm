include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
const int MAX_V=300001;
int n,m,k=501;
vector<pair<int,int>> adj[MAX_V];

int dijkstra(int st, int ed){
    int dist[MAX_V];
    fill(dist, dist+MAX_V, INT_MAX);
    int visited[MAX_V] = {0};
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //min heap {dist, 정점}

    dist[st]=0;
    pq.push({0,st});
    while(!pq.empty()){
        int cur=pq.top().second; pq.pop();
        if(visited[cur]) continue; //이미 방문한 곳이면 무시
        visited[cur]=1;
        for(auto &u:adj[cur]){
            int next=u.first, cost=u.second;
            int next_dist = dist[cur]+cost;
            if(dist[next]>next_dist){
                //최단거리 갱신
                dist[next]=next_dist;
                pq.push({dist[next], next});
            }
        }
    }
    return dist[ed];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<m; j++){
            if(s[j]=='/'){
                adj[i*k+j].push_back({(i+1)*k+(j+1),1});
                adj[(i+1)*k+(j+1)].push_back({i*k+j,1});
                adj[(i+1)*k+j].push_back({i*k+(j+1),0});
                adj[i*k+(j+1)].push_back({(i+1)*k+j,0});
            }
            else{
                adj[i*k+j].push_back({(i+1)*k+(j+1),0});
                adj[(i+1)*k+(j+1)].push_back({i*k+j,0});
                adj[(i+1)*k+j].push_back({i*k+(j+1),1});
                adj[i*k+(j+1)].push_back({(i+1)*k+j,1});
            }
        }
    }
    int ans=dijkstra(0, n*k+m);
    if(ans==INT_MAX) cout<<"NO SOLUTION";
    else cout<<ans;
    return 0;
}
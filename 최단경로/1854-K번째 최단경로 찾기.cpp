#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>> Vertex[1002];
bool visit[1002];
int Dist[1002];
int counting[1002];


void input(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 0; i< m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Vertex[a].push_back({c,b});
        Vertex[b].push_back({c,a});
    }
    for(int i=0;i<1002;i++){
        counting[i] = k;
    }
}



void Dijkstra_Using_Heap()
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, 1));
    Dist[1] = 1;
 
    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
 
        for (int i = 0; i < Vertex[Cur].size(); i++)
        {
            int Next = Vertex[Cur][i].first;
            int nCost = Vertex[Cur][i].second;
 
            if(counting == 0){
                if (Dist[Next] > Cost + nCost){
                    Dist[Next] = Cost + nCost;
                    PQ.push(make_pair(-Dist[Next], Next));
                }
            } else if(counting[Next] > 0){
                if (Dist[Next] > Cost + nCost){
                    Dist[Next] = Cost + nCost;
                    PQ.push(make_pair(-Dist[Next], Next));
                }
            }
        }
    }
}

int main(){
    input();
    
}

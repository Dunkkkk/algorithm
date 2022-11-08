#include <string>
#include <vector>

using namespace std;

int parent[201];
int meadal[201];
bool ans[201];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge (int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (meadal[u] > meadal[v]){
        int temp = u;
        u = v;
        v = temp;
    }
    parent[u] = v;
    if (meadal[u] == meadal[v]) ++meadal[v];

}





int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        parent[i] = i;
        meadal[i] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(computers[i][j] == 1){
                merge(i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        int tmp = find(i);
        if(!ans[tmp]){
            answer++;
            ans[tmp] = true;
        }
    }
    return answer;
}

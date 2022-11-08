#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int t,n,k,d;
int timeArr[100002];
int indegree[100002];
int tt[100002];
bool visit[100002];
queue<int> zero;
vector<int> vertex[100002];

void solve() {
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>timeArr[i];
        }
        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;
            vertex[a].push_back(b);
            indegree[b]++;
        }
        cin>>d;
        for(int i=1;i<=n;i++){
            if(indegree[i] == 0) zero.push(i);
        }
        while(!zero.empty()) {
            int f = zero.front();
            if (f == d and t == 0) {
                cout<<tt[f] + timeArr[f]<<" ";
                break;
            }
            zero.pop();
            for(int i=0;i<vertex[f].size();i++){
                if(!visit[vertex[f][i]]) {
                    visit[vertex[f][i]] = true;
                    indegree[vertex[f][i]]--;
                    if (indegree[vertex[f][i]] == 0) zero.push(vertex[f][i]);
                    tt[vertex[f][i]] = tt[f] + timeArr[f];
                }
                else {
                    indegree[vertex[f][i]]--;
                    if (indegree[vertex[f][i]] == 0) zero.push(vertex[f][i]);
                    tt[vertex[f][i]] = max(tt[vertex[f][i]], tt[f] + timeArr[f]);
                }
            }
        }
        for(int i=0;i<n;i++){
            indegree[i]=0;
            timeArr[i] = 0;
            tt[i]=0;
            visit[i] = false;
            vertex[i].clear();
            if( !zero.empty() ) zero.pop();
        }
        
    }
}




int main() {
    solve();
}

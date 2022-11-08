#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;
int grade[501];
int indegree[501];
int n,m;
pair<pair<int, int>, bool> in;


void solve(){
    pair<int, int> temp[501];
}


void input() {
    int tc;
    cin>>tc;
    while(tc--){
        bool stop = false;
        cin>>n;
        for(int i=0;i<=n;i++){
            indegree[i] = 0;
            grade[i] =0;
        }
        for(int i=1;i<=n;i++){
            cin>>grade[i];
            indegree[grade[i]] = i - 1;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            if(indegree[a] < indegree[b])  {
                cout<<"IMPOSSIBLE";
                stop = true;
                break;
            }
            else {
                indegree[a]--;
                indegree[b]++;
            }
        }
        if(stop) break;
        solve();
    }
    
}


int main() {
    input();
    
}

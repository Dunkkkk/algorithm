#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2147483647

using namespace std;
int n,m;
int arr[101][101];
int ranking[101];
int parent[101];


void pri() {
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int find(int a) {
   
    if(parent[a] == a) return a;
    
    return parent[a] = find(parent[a]);
}


void u(int a, int b) {
    
    int u = find(a);
    int v = find(b);
    
    if(u == v) return;
    if(ranking[u] > ranking[v]) swap(u,v);
    
    parent[u] = v;
    
    if(ranking[u] == ranking[v]) ranking[u]++;
}


void cleanArr() {
    for(int i=0;i<101;i++){
        ranking[i] = 1;
        parent[i] = i;
        for(int j=0;j<101;j++){
            arr[i][j] = MAX;
        }
    }
}

void fw() {
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(arr[i][k] != MAX and arr[k][j] != MAX) arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

void input() {
    cin>>n>>m;
    cleanArr();
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        u(a, b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    fw();
}

pair<int, int> isCheck[101];
void solve() {
    for(int i=0;i<101;i++){
        isCheck[i] = {0,MAX};
    }
    for(int i=1;i<=n;i++){
        int m = 0;
        for(int j=1;j<=n;j++){
            m = max(arr[i][j] == MAX ? -1 : arr[i][j] , m);
        }
        int k = find(i);
        isCheck[k] = isCheck[k].second > m ? make_pair(i, m) : isCheck[k];
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(isCheck[i].second != MAX) ans.push_back(isCheck[i].first);
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}




int main() {
    input();
    solve();
}

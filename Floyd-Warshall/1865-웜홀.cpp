#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct hole {
    int start;
    int end;
    int take;
};
#define INF int(1e9)

int tc,n,m,w;
int g[501][501];
int rg[501][501];

void input() {
    cin>>tc;
    while(tc--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j] = 0;
                rg[i][j] = 0;
            }
        }
        cin>>n>>m>>w;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            g[a][b] = c;
            g[b][a] = c;
            rg[a][b]= c;
            rg[b][a] = c;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j) g[i][j] = 0;
                else if (g[i][j] == 0) g[i][j] = INF;
            }
        }
        for(int i=0;i<w;i++){
            int a,b,c;
            cin>>a>>b>>c;
            rg[a][b] = -c;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
                }
            }
        }
        bool isExist = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][j] + rg[j][i] < 0) isExist = true;
            }
        }
        if(isExist) cout <<"YES";
        else cout<<"NO";
    }
}



int main() {
    input();
}

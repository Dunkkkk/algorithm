#include <iostream>
#include <utility>
#include <queue>

using namespace std;
struct info {
    int h;
    int i;
    int j;
    int day;
};

int n,m,h;
int box[101][101][101];
int dirx[4] = {0, 0, -1, 1};
int diry[4] = {-1, 1, 0, 0};
queue<info> q;




void input() {
    cin>>m>>n>>h;
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>box[i][j][k];
                if (box[i][j][k] == 1) q.push({k,i,j,0});
            }
        }
    }
}

bool isSize(int y, int x) {
    return y>=0 and y<n and x>=0 and x<m;
}
bool check(){
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(box[i][j][k] == 0) return false;
            }
        }
    }
    return true;
}



int main() {
    input();
    info current;
    while(!q.empty()) {
        current = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ni = current.i + diry[i];
            int nj = current.j + dirx[i];
            if (isSize(ni,nj)) {
                if(box[ni][nj][current.h] == 0){
                    box[ni][nj][current.h] = 1;
                    q.push({current.h,ni,nj,current.day + 1});
                }
            }
        }
        if((current.h + 1) < h and box[current.i][current.j][current.h+1] == 0){
            box[current.i][current.j][current.h+1] = 1;
            q.push({current.h+1, current.i,current.j,current.day+1});
        }
        if((current.h - 1) >= 0 and box[current.i][current.j][current.h-1] == 0){
            box[current.i][current.j][current.h-1] = 1;
            q.push({current.h-1, current.i,current.j,current.day+1});
        }
    }
    if(check()) cout<<current.day;
    else cout<<"-1";
}


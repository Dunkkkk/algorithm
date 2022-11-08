#include <iostream>

using namespace std;
int n,m;
int arr[5][5];
int diry[4] = {-1,0,1,0};
int dirx[4] = {0,-1,0,1};
bool visit[5][5];

void input(){
    cin>>n>>m;
}

bool issize(int i, int j){
    return i>=0 and i<n and j>=0 and i<=m;
}

int solve(int y, int x){
    int sol = 0;
    for(int i=0;i<5;i++){
        if(issize(y, x) and issize(y+diry[i%4], x+dirx[i%4]) and issize(y+diry[(i+1)%4], x+dirx[(i+1)%4])){
            if(!visit[y][x] and !visit[y+diry[i%4]][x+dirx[i%4]] and !visit[y+diry[(i+1)%4]][x+dirx[(i+1)%4]]){
                sol = max(sol, 2 * (sol + arr[y][x]) + arr[y+diry[i%4]][x+dirx[i%4]] + arr[y+diry[(i+1)%4]][x+dirx[(i+1)%4]]);
                visit[y][x] =true;
                visit[y+diry[i%4]][x+dirx[i%4]] = true;
                visit[y+diry[(i+1)%4]][x+dirx[(i+1)%4]] = true;
            }
        }
        if (x+1 < m) solve(y,x+1);
        else solve(y+1,0);
    }
    
    return 1;
}




int main(){
    input();
}

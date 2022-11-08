#include <iostream>

using namespace std;
int n;
int arr[501][501];
int dp[501][501];
int diry[4]={-1,1,0,0};
int dirx[4]={0,0,-1,1};

bool issize(int y,int x){
    return x>=0 and x<n and y>=0 and y<n;
}

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
}

int find(int y,int x){
 
    int& ret = dp[y][x];
    if(ret != 0) return ret;
    for(int i = 0;i<4;i++){
        int ny = y+diry[i],nx = x+dirx[i];
        if(issize(ny, nx) and arr[ny][nx] > arr[y][x]){
            ret = max(ret,find(ny,nx)+1);
        }
    }
    return ret;
}




int main(){
    input();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] == 0){
                find(i,j);
            }
        }
    }
    int sol = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] > sol) sol = dp[i][j];
        }
    }
    cout<<sol+1;
}

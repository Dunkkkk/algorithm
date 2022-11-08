#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> love[401];
vector<int> order;
int dirY[4] = {-1,1,0,0};
int dirX[4] = {0,0,-1,1};
int arr[402][402];
int n;

void input(){
    cin>>n;
    for(int i=1;i<=n*n;i++){
        int num;
        cin>>num;
        order.push_back(num);
        for(int j = 0;j<4;j++) {
            int lover;
            cin>>lover;
            love[num].push_back(lover);
        }
    }
}

bool check(int y, int x){
    return x>=1 and x<=n and y>=1 and y<=n;
}

int checkScore(int y,int x,int student){
    int ans = 1;
    for(int i=0;i<4;i++){
        int nY = y + dirY[i];
        int nX = x+ dirX[i];
        if(check(nY, nX)){
            if(arr[nY][nX] != 0){
                bool has = false;
                for(int s : love[student]) if(s==arr[nY][nX]) has = true;
                if(has) ans += 100;
            }
            else ans += 2;
        }
    }
    return ans;
}

int score(int y, int x,int student){
    int ans = 0;
    for(int i=0;i<4;i++){
        int nY = y + dirY[i];
        int nX = x + dirX[i];
        if(check(nY, nX)){
            for(int s : love[student]) if( s == arr[nY][nX] ) ans++;
        }
    }
    return pow(10, ans - 1);
}


void solution(int student){
    int y=0;
    int x=0;
    int score = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] != 0) continue;;
            int cur = checkScore(i, j, student);
            if(score < cur){
                y = i;
                x = j;
                score = cur;
            }
        }
    }
    arr[y][x] = student;
}

int main(){
    input();
    for(int s:order){
        solution(s);
    }
    int ans = 0;

    for(int i = 1; i<=n;i++){
        for(int j=1;j<=n;j++){
            ans += score(i, j, arr[i][j]);
        }
    }
    cout<<ans;
}
/*
 3
 4 2 5 1 7
 3 1 9 4 5
 9 8 1 2 3
 8 1 9 3 4
 7 2 3 4 8
 1 9 2 5 7
 6 5 2 3 4
 5 1 9 2 8
 2 9 3 1 4
 */

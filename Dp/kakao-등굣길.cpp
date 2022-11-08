#include <string>
#include <vector>

using namespace std;
int cache[101][101];
bool arr[101][101];
int ga,se;

bool check(int y,int x){
    return x>=1 and x<=ga and y>=1 and y<=se;
}

int dp(int y,int x){
    int& ret = cache[y][x];
    if(ret != 0) return ret;
    if(y==se and x==ga) return 1;
    if (check(y+1, x) and !arr[y+1][x] and !arr[y][x+1] and check(y, x+1)){
        ret = (dp(y+1,x) + dp(y,x+1)) % 1000000007;
    }
    else if(check(y+1, x) and !arr[y+1][x]){
        ret = dp(y+1,x);
    } else if(check(y, x+1) and !arr[y][x+1]){
        ret = dp(y,x+1);
    }
    return ret;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    ga = m;
    se = n;
    for(vector<int> cur : puddles){
        arr[cur[1]][cur[0]] = true;
    }
    answer = dp(1,1);
    return answer;
}

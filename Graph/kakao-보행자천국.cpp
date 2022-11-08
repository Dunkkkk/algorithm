#include <vector>
#include <iostream>

using namespace std;
int cache[501][501][2];
int MOD = 20170805;
int se,ga;
vector<vector<int>> map;

bool isSize(int y, int x){
    return 0<=y and y<se and 0<=x and x<ga and map[y][x] != 1;
}
//dir == 0 up dir == 1 left
int dp(int y,int x, int dir){
    int& ret = cache[y][x][dir];
    if(y == se-1 and x == ga-1) return ret = 1;
    if(ret != 0) return ret;
    if(map[y][x] == 0){
        if(isSize(y, x+1)) ret += dp(y, x+1, 1) % MOD;
        if(isSize(y+1,x)) ret += dp (y+1, x, 0) % MOD;
    }
    if(map[y][x] == 2){
        if(dir == 0 and isSize(y+1, x)) ret += dp (y+1, x, 0) % MOD;
        else if(dir == 1 and isSize(y, x+1)) ret += dp(y, x+1, 1) % MOD;
    }
    return ret %= MOD;
}



// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    se = m; ga = n; map = city_map;
    dp(0,0,0);
    answer = dp(0,0,0);
    return answer;
}

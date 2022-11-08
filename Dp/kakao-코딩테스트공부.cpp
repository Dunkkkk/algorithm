#include <string>
#include <vector>
#define MAX 2147483647

using namespace std;
int cache[1001][1001];
int a,c;
int disa,disc;
vector<vector<int>> p;

int solve(int al, int co){
    if(al >= disa and co >= disc) return 0;
    al = min(disa, al);
    co = min(disc, co);
    int& ret = cache[al][co];
    
    if(ret != MAX) return ret;
    if(al < disa) ret = min(solve(al+1, co) + 1, ret);
    if(co < disc) ret = min(solve(al, co+1) + 1, ret);
    
    for(int i =0;i<p.size();i++){
        if((p[i][0] <= al and p[i][1] <= co)) {
            ret = min(solve(al + p[i][2], co + p[i][3]) + p[i][4], ret);
        }
    }
    return ret;
}


int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    a = alp;
    c = cop;
    p = problems;
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            cache[i][j] = MAX;
        }
    }
    for(int i=0;i<problems.size();i++){
        disa = max(disa, problems[i][0]);
        disc = max(disc, problems[i][1]);
    }
    answer = solve(a, c);
    return answer;
}

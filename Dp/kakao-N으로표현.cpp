#include <string>
#include <vector>

using namespace std;
vector<int> num;
int dp[32001];

void init(int n){
    int temp = 0;
    for(int i=1;i<9;i++){
        temp = (temp * 10) + n;
        if(temp > 32000) break;
        num.push_back(temp);
        dp[temp]=i;
    }
    for(int i=0;i<32001;i++){
        dp[i]=320001;
    }
}

void find(int n, int chance){
    for(int i=0;i<num.size();i++){
        find(n*)
    }
}


int solution(int N, int number) {
    int answer = 0;
    init(N);
    find(N);
    answer = dp[number] ==  320001 ? -1 : dp[number];
    return answer;
}

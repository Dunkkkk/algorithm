#include <string>
#include <vector>

using namespace std;
vector<int> g[101];
int out[101];
//앞에가 뒤를 가르킴
bool arr[101][101];


int sol(int n){
    int ans = 0;
    int rank=0;
    for(int i=1;i<=n;i++){
        rank = 0;
        for(int j=1;j<=n;j++){
            if(out[j] == 0){
                
            }
        }
    }
    return ans;
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++){
        out[results[i][0]]++;
        arr[results[i][0]][results[i][1]] = true;
    }
    answer = sol(n);
    return answer;
}

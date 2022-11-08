#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[101];
int n ,m;
int ans[101];
int answer[101];
bool ind[101];

void input(){
    cin >> n >>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        ind[b] = true;
    }
}

int dfs(int num){
    if(ans[num] != 0) return ans[num];
    int sol = 1;
    for(int tmp : arr[num]){
        sol += dfs(tmp);
    }
    ans[num] = sol;
    return sol;
}

void fill(int num,int sol){
    if(answer[num] != 0) answer[num] += (sol);
    else answer[num] += sol-1;
    for(int tmp : arr[num]){
        fill(tmp,sol);
    }
}

int main(){
    input();
    for(int i=1;i<=n;i++){
        if(!ind[i]){
            dfs(i);
            fill(i,ans[i]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<answer[i]<<"\n";
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2147483647

using namespace std;

vector<int> v[51];
int n;

void input() {
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(i == 0) continue;
        v[temp].push_back(i);
    }
}

int dfs(int node){
    if(v[node].size() == 0) return 0;
    
    int temp = 0;
    vector<int> cute;
    for(int a : v[node]){
        int tmp = dfs(a) + 1;
        temp = max(temp, tmp);
        cute.push_back(tmp);
    }
    temp = 0;
    sort(cute.begin(), cute.end());
    reverse(cute.begin(), cute.end());
    for(int i=0;i<cute.size();i++) {
        temp = max(cute[i] + i, temp);
    }
    temp = temp < v[node].size() ? v[node].size() : temp;
    return temp;
}

int main() {
    input();
    cout<<dfs(0);
}

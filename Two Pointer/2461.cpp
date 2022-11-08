#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define MAX 2147483647

using namespace std;
vector<pair<int, int>> arr;
int visit[1001];
int n,m;

int solve() {
    int s=0,e=0,count=0;
    int ans = MAX;
    while(s <= arr.size()){
        if(count == n) {
            ans = min(ans, arr[s-1].first - arr[e].first);
            visit[arr[e].second]--;
            if(visit[arr[e].second] == 0) count--;
            e++;
        }
        else {
            if(visit[arr[s].second] == 0) count++;
            visit[arr[s].second]++;
            s++;
        }
    }
    return ans;
}

void input() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            arr.push_back({a,i});
        }
    }
    sort(arr.begin(), arr.end());
    cout<<solve();
}

int main() {
    input();
}

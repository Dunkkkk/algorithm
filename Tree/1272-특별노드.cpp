#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct node {
    int weight = 0;
    bool visit = false;
    vector<int> child;
};
int dp[1001][1001];
node arr[1001];
int newWeight[1001];
int n,root;

void input(){
    cin>>n>>root;
    for(int i=1;i<=n;i++){
        cin>>arr[i].weight;
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        arr[a].child.push_back(b);
        arr[b].child.push_back(a);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = 500000000;
        }
    }
}

int solve(int node, int specialNode) {
    if(arr[node].child.size() == 1) { return arr[node].weight - arr[specialNode].weight; }
    int& ret = dp[node][specialNode];
    if(ret != 500000000) return ret;
    int a=0,b=0;
    arr[node].visit = true;
    for(int i=0;i<arr[node].child.size();i++){
        int child = arr[node].child[i];
        if (arr[child].visit == false) {
            if(node != root) a += solve(child, specialNode);
            b +=  solve(child, node);
        }
    }
    arr[node].visit = false;
    a += arr[node].weight - arr[specialNode].weight;
    b += arr[node].weight;
    
    if (node != root) ret = min(a,b);
    else ret = b;
    return ret;
}

int main() {
    input();
    solve(root, root);
    cout<<dp[root][root];
}

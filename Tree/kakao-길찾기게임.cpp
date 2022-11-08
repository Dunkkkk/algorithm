#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> node;
bool visit[1002];
vector<int> height;
vector<pair<int, int>> location[100002];
int rootNode;
int tree[100002];

//dir = 1 right, dir = 0 left
void dfs(int parentX, int left, int right, int index, int level){
    if(level == height.size()) return;
    
    for(int i=0;i<location[height[level]].size();i++){
        int currentX = location[height[level]][i].first;
        int currentNode = location[height[level]][i].second;
        
        if(currentX > left and currentX < right){
            if(parentX < currentX) {
                tree[index * 2 + 1] = currentNode;
                dfs(currentX, parentX, right, index * 2 + 1, level+1);
            }
            else {
                tree[index * 2] = currentNode;
                dfs(currentX, left, parentX, index * 2, level+1);
            }
        }
    }
}

void makeTree() {
    vector<pair<int, int>> y;
    int maxx= 0 ;
    for(int i=0;i<node.size();i++){
        maxx = max(node[i][0], maxx);
        if(!visit[node[i][1]]) height.push_back(node[i][1]);
        location[node[i][1]].push_back({node[i][0], i+1});
    }
    sort(height.begin(), height.end());
    reverse(height.begin(), height.end());
   
    tree[1] = location[height[0]][0].second;
    
    dfs(location[height[0]][0].first,-1,maxx + 1,1,1);
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<tree[i]<<" ";
    }
}



vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    node = nodeinfo;
    makeTree();
    
    
    return answer;
}



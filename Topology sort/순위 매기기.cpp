#include <string>
#include <vector>
#include <queue>
#include <utility>
#include<iostream>

using namespace std;

struct node {
    vector<int> dir[3];
};

node v[101];
int indegree[101];
int ans;
int person;
int c;
bool visit[101];
// 1 == up 2 == down 0 == both
int dfs(int index,int isUp){
    
    
}

void clean(){
    for(int i=0;i<=person;i++) visit[i] = false;
}

int solution(int n, vector<vector<int>> results) {
    person = n;
    int answer = 0;
    for(vector<int> a : results) {
        v[a[1]].dir[1].push_back(a[0]);
        v[a[0]].dir[2].push_back(a[1]);
    }
    for(int i=1;i<=n;i++){
        dfs(i,3);
        if(c == person) answer++;
        cout<<endl;
        c=0;
        clean();
    }
    return answer;
}

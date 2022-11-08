#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

priority_queue<int> trees[102];
queue<int> tree[102];
vector<vector<int>> e;
vector<int> t;
vector<int> line;
vector<int> visitLeaf;

int allLeaf;
int repeatTerm[102];
bool visit[102];
int leafStartWhere[102];
int many_2[102];
int answerVectorSize;
int many_1[102];
int countLeaf;
int totalLeaf;


void clean(){
    for(int i=1;i<=t.size();i++){
        while(!tree[i].empty()) tree[i].pop();
    }
}

void input(){
    clean();
    for(int i=0;i<e.size();i++){
        trees[e[i][0]].push( -1 * e[i][1]);
    }
    for(int i=1;i<=t.size();i++){
        while(!trees[i].empty()){
            tree[i].push(trees[i].top() * -1);
            trees[i].pop();
        }
        
    }
}

void findLength(){
    int maxLength = 0;
    for(int i=0;i<line.size();i++){
        int temp = t[line[i] - 1] / 3;
        temp += t[line[i] - 1] % 3 > 0 ? 1 : 0;
        maxLength = max(maxLength, leafStartWhere[line[i]] + (repeatTerm[line[i]] * (temp - 1)) );
    }
    answerVectorSize = maxLength;
    for(int i=0;i<line.size();i++){
        many_1[line[i]] = ((answerVectorSize - leafStartWhere[line[i]]) / repeatTerm[line[i]] ) + 1;
        many_2[line[i]] = ((answerVectorSize - leafStartWhere[line[i]]) / repeatTerm[line[i]] ) + 1;
    }
    input();
}

void solve(int index){
    if(tree[index].size() == 0 and countLeaf < answerVectorSize) {
        countLeaf++;
        many_1[index]--;
        visitLeaf.push_back(index);
        solve(1);
    }
    else {
        int f = tree[index].front();
        tree[index].pop();
        tree[index].push(f);
        if(countLeaf < answerVectorSize) solve(f);
    }
}

void dfs(int index, int value){
    if(tree[index].size() == 0 and leafStartWhere[index]==0) {
        countLeaf++;
        totalLeaf++;
        line.push_back(index);
        repeatTerm[index] = value;
        leafStartWhere[index] = countLeaf;
        dfs(1,1);
    }
    else if(tree[index].size() == 0){
        countLeaf++;
        dfs(1,1);
    }
    else {
        int f = tree[index].front();
        tree[index].pop();
        tree[index].push(f);
        if(totalLeaf < allLeaf) dfs(f, tree[index].size() * value);
    }
}

int ouputToSmall(int left, int tar){
    if(left == 1 and tar > 0 and tar <= 3) return tar;
    if(left == 1 and (tar > 0 or tar <= 0)) return -1;
    if(left > tar) return  -1;
    int temp = 0;
    for(int i=1;i<=3;i++){
        if (ouputToSmall(left - 1, tar - i) != -1) return i;
    }
    return -1;
}

void forMain(){
    input();
    dfs(1,1);
    findLength();
    countLeaf = 0;
    solve(1);
}


vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    e = edges; t = target;
    for (int a: target) if(a!= 0) allLeaf++;
    
    forMain();
    
    for(int i=0;i<visitLeaf.size();i++){
        int minus = ouputToSmall(many_2[visitLeaf[i]], target[visitLeaf[i] - 1]);
        if (minus == -1) break;
        answer.push_back(minus);
        many_2[visitLeaf[i]]--;
        target[visitLeaf[i] -1] -= minus;
    }
    if(answer.size() != visitLeaf.size()) {
        answer.clear();
        answer.push_back(-1);
    }
    
    return answer;
}

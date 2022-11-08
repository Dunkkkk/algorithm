#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> g[51];
int visit[51];


bool check(string a, string b){
    int check = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            check++;
        }
        if(check>=2) return false;
    }
    return true;
}

void init(){
    for(int i=0;i<51;i++){
        visit[i] = 0;
    }
}


int solution(string begin, string target, vector<string> words) {
    int answer = 100;
    int goal = -1;
    vector<int> start;
    int i;
    for(i = 0;i<words.size();i++){
        if(check(words[i],begin)) start.push_back(i);
        if(words[i] == target){
            goal = i;
        }
    }
    if (goal == -1) return 0;
    for(int i=0;i<words.size();i++){
        for(int j=i+1;j<words.size();j++){
            if(check(words[i],words[j])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    
    for(int s: start){
        init();
        queue<int> q;
        q.push(s);
        visit[s] = 1;
        while (!q.empty()) {
            int cur = q.front();
            cout<<cur;
            if(cur == goal) {
                answer = min(answer, visit[cur]);
                break;
            }
            q.pop();
            for(int c: g[cur]){
                if(visit[c] == 0) {
                    q.push(c);
                    visit[c] = visit[cur] + 1;
                }
            }
        }
    }
    if(answer == 100) return 0;
    return answer;
}

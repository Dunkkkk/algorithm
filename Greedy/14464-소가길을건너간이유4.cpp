//
// Created by changgyo seo on 2023/01/03.
//
#include<iostream>
#include<utility>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int n,m;
priority_queue<int> chicken;
stack<int> s;
priority_queue<pair<int,int>> cow;

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        chicken.push(-temp);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cow.push({-a,-b});
    }
    int answer = 0;

    priority_queue<int> pq;
    while(!chicken.empty()){
        int chickenTime = -chicken.top();
        chicken.pop();
        while(!cow.empty() and -cow.top().first <= chickenTime) { pq.push(cow.top().second); cow.pop(); }
        while(!pq.empty() and -pq.top() < chickenTime) { pq.pop(); }
        if(!pq.empty()) {
            pq.pop();
            answer++;
        }
    }
    cout<<answer;
}
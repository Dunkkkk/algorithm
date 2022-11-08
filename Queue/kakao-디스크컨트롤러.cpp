#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;
bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end(), cmp);
    priority_queue<pair<int, int>> pq;
    jobs.push_back({-1,0});
    int k = 0;
    int cur=0;
    while(!pq.empty() or k < jobs.size()-1){
        for(;jobs[k][0] <= cur and jobs[k][0] != -1;k++) pq.push({-jobs[k][1],jobs[k][0]});
        if(pq.empty()) cur++;
        else {
            cur += -pq.top().first;
            answer += cur-pq.top().second;
            pq.pop();
        }
    }
    jobs.pop_back();
    return answer / jobs.size();
}

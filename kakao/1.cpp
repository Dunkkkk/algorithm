
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
priority_queue<pair<int,int>> q;

int solution(vector<vector<int>> flowers) {
    int answer = 0;
    for (vector<int> a: flowers) q.push({-a[0], -a[1]});
    int start = -q.top().first;
    int end = -q.top().second;
    q.pop();
    int s = q.size();
    for (int i = 0; i<=s; i++) {
        if(q.empty()){
            answer += end - start;
            break;
        }
        pair<int, int> temp = {q.top().first * (-1),q.top().second * (-1)};
        q.pop();
        if (temp.first > end) {
            answer += end - start;
            start = temp.first;
            end = temp.second;
        } else if (start <= temp.first and end <= temp.second) {
            end = temp.second;
        }
    }
    return answer;
}
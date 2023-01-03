//
// Created by changgyo seo on 2022/12/26.
//
#include <string>
#include <queue>
#include<iostream>
#include <vector>

using namespace std;
priority_queue<int> pq;
int N,K;
vector<int> Enemy;

int solve(){
    int i = 0;
    for(;i<Enemy.size();i++) {
        pq.push(-Enemy[i]);
        if (pq.size() > K) {
            int temp = -pq.top();
            pq.pop();
            if (N - temp >= 0) N -= temp;
            else break;
        }
    }
    return i;
}


int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    N = n; K = k; Enemy = enemy;
    answer = solve();

    return answer;
}

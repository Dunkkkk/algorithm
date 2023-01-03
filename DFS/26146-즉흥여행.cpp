//
// Created by changgyo seo on 2022/12/28.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n,m;
vector<int> airLine[200001];
int visit[200001];
stack<int> trace;

int findCycle(int airPort, int order) {
    for(int nextAirPort : airLine[airPort]) {
        if(visit[nextAirPort] != 0) {}
        else {}
    }
}


int main() {
    cin>>n>>m;
    for(int i=0;i<=n;i++) cycle[i] = i;
    for(int i=0;i<m;i++) {
        int start, end;
        cin>>start>>end;
        airLine[start].push_back(end);
    }


}
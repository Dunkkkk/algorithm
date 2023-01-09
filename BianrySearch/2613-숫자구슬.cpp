//
// Created by changgyo seo on 2023/01/05.
//
#include <iostream>
#include <algorithm>

using namespace std;

int marble[301];
int n,m;

bool isOkay(int limit){
    int grpCnt = 1;
    int total = 0;
    for(int i=0;i<n;i++){
        total += marble[i];
        if(total > limit){
            grpCnt ++;
            total = marble[i];
        }
    }

    return grpCnt <= m;
}

int findLimit(int start, int end) {
    if(start >= end) return start;
    int mid = ( start + end ) / 2;

    if(isOkay(mid)) return findLimit(start, mid);
    else return findLimit(mid+1, end);
}



int main() {
    cin>>n>>m;
    int mini = 101;
    int totalSum = 0;
    for(int i=0;i<n;i++){
        cin>>marble[i];
        mini = min(mini, marble[i]);
        totalSum += marble[i];
    }
    int limit = findLimit(mini, totalSum);
    int sum = 0;
    int left = 0;
    cout<<limit<<endl;
    int grpCnt = 1;
    int total = 0;
    int ggg = 0;
    for(int i=0;i<n;i++){
        total += marble[i];
        ggg++;
        if(total > limit){
            grpCnt ++;
            cout<<ggg - 1<<" ";
            ggg = 1;
            total = marble[i];
        }
    }
    cout<<ggg;
}
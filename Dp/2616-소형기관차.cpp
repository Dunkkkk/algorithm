//
// Created by changgyo seo on 2022/12/26.
//
#include<iostream>
#include<algorithm>

using namespace std;

int cache[50001][4];
int train[50001];
int n,m;
int pSum[50001];

int dp(int index, int left){
    if(index >= n or left == 0) return 0;

    int& ret = cache[index][left];
    if(ret != 0) return ret;
    ret = max(ret, dp(index + 1, left));
    if(left > 0 and index + m < n) ret = max(ret, dp(index + m, left - 1) + (pSum[index + m] - pSum[index]));
    else if(left > 0) ret = max(ret, dp(n, left - 1) + (pSum[n] - pSum[index]));
    //if(index == 0) cout<<(pSum[index + m])<<"sdsds\n";
    //cout<<index <<" "<<left<<" "<<ret<<endl;
    return ret;
}

int main(){
    cin>>n;
    pSum[0] = 0;
    for(int i=0;i<n;i++){
        cin>>train[i];
        pSum[i+1] += pSum[i] + train[i];
    }
    cin >> m;

    cout<<dp(0, 3);
}
//1 2 3 4 5
//0 1 3 6 10  15

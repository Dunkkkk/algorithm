#include<iostream>
#include<algorithm>
#define MAX 2147483647

using namespace std;

int cache[501][501];
int numbers[501];
int sum[501];

int dp(int start, int end){

    if(start == end) return 0;
    int& ret = cache[start][end];
    if(ret != MAX) return ret;

    for(int i=start; i<end;i++){
        int now = start != 0 ? numbers[end] - numbers[start-1] : numbers[end];
       // cout<<start<<" "<<end<<" "<<now<<"\n";
        ret = min(ret, dp(start, i) + dp(i + 1,end) + now);
    }

    return ret;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--) {
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                cache[i][j] = MAX;
            }
        }
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>numbers[i];
        for(int i=1;i<n;i++) numbers[i] += numbers[i-1];
        cout<<dp(0,n-1)<<"\n";
        for(int i=0;i<501;i++) {
            numbers[i] = 0;
            sum[i] = 0;
        }
    }

}
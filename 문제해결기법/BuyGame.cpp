#include <iostream>
#include <algorithm>
#define MAX 2147483647

using namespace std;
int cache[12][2];
string number;

int cToi(char a){
    return a - '0';
}

int dp(int idx, int isSpend){
    int& ret = cache[idx][isSpend];
    if(idx == number.size() - 1){
        if(isSpend) return cToi(number[idx]);
        else return 10 - cToi(number[idx]);
    }
    if(ret != MAX) return ret;
    if(isSpend) {
        ret = min(ret, dp(idx+1, 1) + cToi(number[idx]));
        ret = min(ret, dp(idx+1, 0) + cToi(number[idx]) + 1);
    }
    else {
        ret = min(ret, dp(idx+1, 1) + 10 - cToi(number[idx]));
        ret = min(ret, dp(idx+1, 0) + 10 - (cToi(number[idx]) + 1));
    }
    return ret;
}

void clean() {
    for(int i=0;i<12;i++){
        for(int j=0;j<2;j++){
            cache[i][j] = MAX;
        }
    }
}

int main() {
    int tc;
    cin>>tc;
    while(tc--){
        clean();
        string temp;
        cin>>temp;
        number = '0' + temp;
        cout<<dp(0,1)<<"\n";
    }
}

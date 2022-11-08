#include <iostream>

using namespace std;
int n;
long cache[31][61];


bool isSize(int whole, int half) {
    return whole <= n and half <= 2*n and whole >= 0 and half>=0;
}

long dp(int whole, int half){
    if (!isSize(whole, half)) return 0;

    long& ret = cache[whole][half];
    if(ret != 0) return ret;

    ret = dp(whole, half - 1) + dp(whole - 1, half + 1);

    return ret;
}

void clearArr(){
    for(int i=0;i<31;i++){
        for(int j=0;j<61;j++){
            cache[i][j] = 0;
            if(i == 0) cache[i][j] = 1;
        }
    }
}

void solve(){
    while(1){
        cin>>n;
        if (n==0) break;
        clearArr();
        dp(n,0);
        cout<<cache[n][0];
    }
}


int main(){
    solve();
}

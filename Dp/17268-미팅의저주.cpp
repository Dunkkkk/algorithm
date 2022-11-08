#include <iostream>

using namespace std;
int n;
long long cache[10001];

void input(){
    cin>>n;
    cache[2] = 1;
    cache[0] = 1;
}

long long dp(int number){
    long long& ret = cache[number];
    if (ret != 0 ) return ret;
    
    for(int i = 0; i <= number; i += 2){
        ret += ((dp(number - i - 2)% 987654321) * (dp(i)% 987654321))%987654321;
        ret %= 987654321;
    }
    
    return ret;
}


int main(){
    input();
    dp(n);
    cout<<cache[n] % 987654321;
}

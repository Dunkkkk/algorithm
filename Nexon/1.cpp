#include<iostream>

using namespace std;

int minNum(int samDaily, int kellyDaily, int difference) {
    float sam = samDaily;
    float kelly = kellyDaily;
    float diff = difference;
    int ans;
    if(kelly - sam > 0) ans = (diff / (kelly - sam)) + 1;
    else ans = -1;
    
    return ans;
}


int main() {
    cout<<minNum(3, 5, 5);
}

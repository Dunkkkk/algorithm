#include <iostream>

using namespace std;
int n,m;

void input() {
    cin>>n>>m;
}

string makeMod(int c){
    string ans = "";
    int half = 0;
    if(c % 2 == 0){
        half = c / 2;
        for(int i=0;i< c/2;i++) ans.push_back('A');
        for(int i=c/2;i<c;i++) ans.push_back('B');
    }
    else {
        half = 1 + (c / 2);
        for(int i=0;i< (c/2)+1 ;i++) ans.push_back('A');
        for(int i=(c/2)+1;i<c;i++) ans.push_back('B');
    }
    int sub = (half) * (c/2) - m;

    char temp = ans[half];
    ans[half] = ans[half - sub];
    ans[half - sub] = temp;
    return ans;
}

string solve() {
    string ans = "";
    if(n % 2 == 0 and (n/2) * (n/2) < m) return "-1";
    else if(n % 2 == 1 and ((n/2) + 1) * (n/2) < m) return "-1";
    for(int i=0;i<n;i++){
        int total = n-i;
        if(m == 0) ans.push_back('B');
        else if(total % 2 == 0 and (total / 2) * (total / 2) > m) ans.push_back('B');
        else if(total % 2 == 1 and ((total / 2) + 1) * (total / 2) > m) ans.push_back('B');
        else {
            if(!ans.empty()) {
                ans.pop_back();
                ans += makeMod(total + 1);
            }
            else {
                ans += makeMod(total);
            }
            break;
        }
    }
    return ans;
}



int main() {
    input();
    cout<<solve();
    
}

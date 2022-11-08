#include <iostream>
#include <stack>

using namespace std;
string s;
int t[1000001];
int st[1000001];

int twopoint(){
    int m = 0;
    int f = 0,b = 0;
    int current = 0;
    
    while(b <= s.size() - 1) {
        if (current >= 0 and f < s.size()){
            current += t[f];
            if(current == 0 and s[b+1] != 'C')  m = max(m, f-b+1);
            f++;
        }
        else if (current < 0 or f == s.size()) {
            current -= t[b];
            if(current == 0 and s[b+1] != 'C')  m = max(m, f-(b+1));
            b++;
        }
    }
    
    return m;
}


void input() {
    int tc;
    cin>> tc;
    while(tc--){
        cin>>s;
        for(int i=s.size()-1;i>=0;i--){
            t[s.size() - 1 - i] = s[i] == 'T' ? 1 : -1;
        }
        cout<<twopoint()<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
}


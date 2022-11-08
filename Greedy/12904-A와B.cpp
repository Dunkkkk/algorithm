#include <iostream>

using namespace std;
string s,t;

void input(){
    cin>>s>>t;
}
bool check(){
    for(int i=0;i<s.size();i++) if(s[i] != t[i]) return false;
    return true;
}

void reverse(int s, int e){
    while(s<e){
        char temp = t[s];
        t[s] = t[e];
        t[e] = temp;
        e--; s++;
    }
}

int main() {
    input();
    int isReverse = 1;
    for(int i=t.size()-1;i>=s.size();i--){
        if(t[i] == 'B') { reverse(0, i-1); }
    }
    cout << check() ? 1 : 0;
}



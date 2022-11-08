#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct result{
    bool isWin;
    string word;
};

priority_queue<char, vector<char>, greater<char>> q;
int alphabet[27];
vector<char> s;
int n;

void input() {
    cin>>n;
    string temp;
    cin>>temp;
    for(char a : temp){
        alphabet[a - 'a']++;
        s.push_back(a);
        q.push(a);
    }
}

result solve(){
    string hei;
    string sang;
    
    for(int i = s.size()-1;i >= 0;i--){
        char t = s[i];
        sang.push_back(t);
        i--;
        
        while(alphabet[s[1] == 0]) q.pop();
        t = q.top();
        hei.push_back(t);
        alphabet[t - 'a']--;
        q.pop();
    }
    return {hei < sang, hei};
}


int main() {
    input();
    result answer = solve();
    cout<<(answer.isWin ? "DA\n" : "NE\n");
    cout<<answer.word;
}

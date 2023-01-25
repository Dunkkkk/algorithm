#include <iostream>
#include <stack>

using namespace std;
string f,s;
int idx;



int solve(string s) {
    int ans = 0;
    if(s[idx] == ')') return 1;
    for(;s[idx] != ')';idx++){
        if(s[idx] == ')')  {
            ans += 1;
            idx++;
        }
        else {
            ans += solve(s);
        }
    }
    //idx++;
    return ans * 2;
}
void input(){
    int tc;
    cin>>tc;
    while(tc--){
        idx=0;
        cin>>f>>s;
        string k = "(" + f + ")";
        int tmp = solve(k);
        k = "(" + s + ")";
        idx = 0;
        int temp = solve(k);
        cout<<tmp<<" "<<temp;
        if(tmp == temp) cout<<"="<<"\n";
        else if (tmp > temp) cout<<">"<<"\n";
        else cout<<"<"<<"\n";
    }
}


int main() {
    input();
}

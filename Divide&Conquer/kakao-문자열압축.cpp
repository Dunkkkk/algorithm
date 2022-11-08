#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
string str;
int result = 2147483647;


vector<string> divide(int size){
    string temp;
    vector<string> returnValue;
    for(int i=0;i<str.size();i++){
        temp.push_back(str[i]);
        if(temp.size() == size) {
            returnValue.push_back(temp);
            temp = "";
        }
    }
    if(temp != "") returnValue.push_back(temp);
    return returnValue;
}

string iTos(int a){
    if(a == 1 or a == 0) return "-";
    vector<char> ans;
    while(a){
        int first = a % 10;
        ans.push_back(first + '0');
        a /= 10;
    }
    reverse(ans.begin(), ans.end());
    string returnValue;
    for(char a : ans) returnValue.push_back(a);
    
    return returnValue;
}

void print(vector<string> temp){
    for (string a : temp) cout<<a<<"-";
    cout<<endl;
}

void solve(){
    for(int i=1; i<=str.size()/2 + 1 ;i++){
        vector<string> temp = divide(i);
        temp.push_back("");
        //print(temp);
        int c = 1;
        string ans;
        for(int j=0;j<temp.size()-1;j++){
            if(temp[j] != temp[j+1]) {
                ans += iTos(c) + temp[j];
               // cout<<ans<<endl;
                c = 1;
            }
            else if(temp[j] == temp[j+1]) c++;
            
        }
      //  cout<<ans;
       // cout<<endl;
        int tmp = 0;
        for(int j=0;j<ans.size();j++){
            if((ans[j] >= 'a' and ans[j] <= 'z') or (ans[j] >= '0' and ans[j] <= '9')) tmp++;
        }
       // cout<<tmp<<endl;
        result = min(result, tmp);
    }
    
}



int solution(string s) {
    int answer = 0;
    str = s;
    solve();
    answer = result;
    cout<<answer;
    return answer;
}
//
//
//int main(){
//    solution("ababababababcabababababab");
//}

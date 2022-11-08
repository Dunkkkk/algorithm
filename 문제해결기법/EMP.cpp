#include <iostream>
#define MAX 2147483647

using namespace  std;
string alpabet[26];
int n,m,k;
string ans;

string diff(){
    string answer;
    for(int i=0;i<k;i += m){
        char result = 'a';
        int temp  = MAX;
        for(int x=0;x<n;x++){
            int check = 0;
            for(int j=0;j<m;j++) {
                if(alpabet[x][j] != ans[i+j]) check++;
            }
            if(temp > check) {
                result = 'A' + x;
                temp = check;
            }
        }
        answer.push_back(result);
    }
    return answer;
}

void input() {
    int tc;
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            alpabet[i] = str;
        }
        cin>>k>>ans;
        cout<<diff()<<"\n";
    }
}

int main() {
    input();
}

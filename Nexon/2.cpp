#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> temp;
string s;
string t;
int answer=-1;

bool isOkay(int index){
    int tindex = 0;
    for(int i=0;i < temp[index].size(); i++){
        if(temp[index][i] == t[tindex]){
            tindex++;
        }
    }
    return tindex == t.size();
}

void bs(int left, int right){
    if(left > right) return;
    int mid = (left + right) / 2;
    if(left == right){
        if(isOkay(left)){
            answer = max(answer, left);
        }
        return;
    }
    else if(isOkay(mid)) {
        answer = max(mid, answer);
        bs(mid + 1, right);
    }
    else bs(left, mid);
}

int getMaximumRemovals(vector<int> order, string source, string target) {
    int ans;
    s=source; t=target;
    for(int i=0;i<order.size();i++){
        source[order[i] - 1] = '-';
        temp.push_back(source);
    }
    bs(0, s.size()-1);
    ans = answer + 1;
    return ans;
}

int main(){

    vector<int> tempss = {7,1,2,5,4,3,6};
    cout<<getMaximumRemovals(tempss, "abbabaa", "bb");
}


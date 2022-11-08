#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>arr;

int stoi(char* tmp){
    int ans = 0;
    bool check = false;
    if(*tmp == '-') {
        check = true;
        tmp++;
    }
    while(*tmp){
        ans = ans * 10 + (*tmp - '0');
        tmp++;
    }
    return check ? ans * -1 : ans ;
}

bool cmp(int a,int b){
    return b < a;
}


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(string cur : operations){
        if(cur[0] != 'D'){
            int tmp = stoi(&(cur[2]));
            arr.push_back(tmp);
            
        }else {
            if(arr.empty()) continue;
            if(cur[2] == '-'){
                sort(arr.begin(), arr.end(),cmp);
            }else{
                sort(arr.begin(), arr.end());
            }
            arr.pop_back();
        }
    }
    sort(arr.begin(), arr.end());
    if(!arr.empty()){
        answer.push_back(arr[arr.size()-1]);
        answer.push_back(arr[0]);
    } else {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

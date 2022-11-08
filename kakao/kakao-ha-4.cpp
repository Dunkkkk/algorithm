#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
string current;

int isTwo(int size){
    int temp = 1;
    while(true) {
        temp = temp * 2;
        if (size <= temp - 1) return temp - 1;
    }
    return 0;
}

string lTos(long long a){
    string ans;
    while (true){
        ans.push_back( (a % 2) + '0');
        a = a / 2;
        if (a == 0) break;
    }
    int wantSize = isTwo(ans.size());
    while(ans.size() < wantSize) ans.push_back('0');
    reverse(ans.begin(), ans.end());
    //cout<<ans<<endl;
    return ans;
}

bool findAns(int start, int end){
    
    if(start == end) return true;
    int mid = (start + end) / 2;
    if(current[mid] == '0'){
        if (current[(mid + start) / 2] == '1' or current[(end + mid) / 2] == '1') return false;
        return true;
    }
    if(findAns(start, mid) and findAns(mid + 1, end)) return true;
    
    else return false;

}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(int i=0;i<numbers.size();i++){
        current = lTos(numbers[i]);
        answer.push_back(findAns(0,current.size()-1) ? 1 : 0);
    }

    return answer;
}

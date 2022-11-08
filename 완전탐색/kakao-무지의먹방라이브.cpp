#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr;
int team[300001]={0,};
int num[300001];
vector<int> leader;


bool cmp(pair<int, int> a,pair<int, int> b){
    if(a.first == b.first){
        return team[a.second] != 1;
    }
    return a.first > b.first;
}


int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    for(int i=0;i<sales.size();i++){
        answer += sales[i];
    }
    num[1] = 1;
    for(int i=0;i<links.size();i++){
        if(team[links[i][0]] == 0) {
            leader.push_back(links[i][0]);
            team[links[i][0]]++;
        }
        team[links[i][0]]++;
        num[links[i][1]] = links[i][0];
    }
    
    sort(arr.begin(), arr.end(), cmp);
    for(int i=0;i<arr.size();i++){
        if(team[num[arr[i].second]] > 1){
            answer -= arr[i].first;
            team[num[arr[i].second]]--;
        }
    }
    



    return answer;
}

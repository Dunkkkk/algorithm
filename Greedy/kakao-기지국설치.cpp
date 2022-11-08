#include <iostream>
#include <vector>
using namespace std;
int range;


int need(int s, int e){
    //cout<<s<<" "<<e;
    if (s >= e) return 0;
    int ans = ( e - s  + 1) / ((range * 2) + 1);
    int mod = ( e - s + 1) % ((range * 2) + 1) > 0 ? 1 : 0;
    //cout<<" "<<ans+mod<<endl;
    return ans + mod;
}

int solution(int n, vector<int> stations, int w){
    int answer = 0;
    range= w;
    for(int i=0;i<stations.size();i++){
        if(i==0){
            answer += need(1,stations[i] - w - 1);
        }
        if(i==stations.size() - 1){
            answer += need(stations[i] + w + 1, n);
        }
        if(i > 0 and i <= stations.size()-1) answer += need(stations[i-1] + w + 1, stations[i] - w - 1);
    }

    return answer;
}

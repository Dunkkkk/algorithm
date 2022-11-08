#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> periods, vector<vector<int>> payments, vector<int> estimates) {
    vector<int> answer;
    int cur = 0;
    int nex = 0;
    int n = periods.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=1;j<payments[i].size();j++){
            sum += payments[i][j];
        }
        bool vip=false;
        bool nextvip = false;
        if((sum+payments[i][0]>=900000 and periods[i] >= 24) or (sum+payments[i][0]>=600000 and periods[i]>=60)) vip = true;
        if((sum+estimates[i] >= 900000 and periods[i]+1>=24) or (sum+estimates[i]>=600000 and periods[i]+1>=60)) nextvip = true;
        if(vip and !nextvip) cur++;
        if(!vip and nextvip) nex++;
    }
    answer.push_back(nex);
    answer.push_back(cur);
    return answer;
}

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;
map<string, int> recent;


int solution(vector<string> id_list, int k) {
    int answer = 0;
    for(int i=0;i<id_list.size();i++){
        string temp;
        for(int j=0;j < id_list[i].size();j++){
            temp.push_back(id_list[i][j]);
            if(id_list[i][j] == ' ' or j == id_list[i].size() - 1) {
                if(j != id_list[i].size() - 1) temp.pop_back();
                if (recent[temp] != i + 1) {
                    recent[temp] = i+1;
                    m[temp]++;
                }
                temp.clear();
            }
        }
    }
    for (auto iter = m.begin() ; iter !=  m.end(); iter++){
        if(iter->second > k) answer += k;
        else answer += iter->second;
    }

    return answer;
}
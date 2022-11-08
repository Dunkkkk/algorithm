#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
map<string, string> m;
vector<string> timeline;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

void parsing(string inst){
    vector<string> result = split(inst, ' ');
    switch (inst[0]) {
        case 'E':
            if(m.find(result[1]) != m.end()) m.find(result[1])->second = result[2];
            else m.insert({result[1],result[2]});
            timeline.push_back(result[1]+"E");
            break;
        case 'C':
            m.find(result[1])->second = result[2];
            break;
        case 'L':
            timeline.push_back(result[1]+"L");
            break;
        default:
            break;
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0;i<record.size();i++){
        parsing(record[i]);
    }
    for(int i=0;i<timeline.size();i++){
        if(timeline[i][timeline[i].size()-1]=='E'){
            timeline[i].pop_back();
            string temp = m.find(timeline[i])->second + "님이 들어왔습니다.";
            answer.push_back(temp);
        }else {
            timeline[i].pop_back();
            string temp = m.find(timeline[i])->second + "님이 나갔습니다.";
            answer.push_back(temp);
        }
    }
    return answer;
}

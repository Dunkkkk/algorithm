#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
int service[300001];
int dataCapacity[300001];

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
       
    }
    return answer;
}

int scg(int s,int e,int num){
    int mid = (s+e)/2;
    if(s>e) return 0;
    if(dataCapacity[mid]==num) return mid;
    if(dataCapacity[mid] < num) scg(s,mid,num);
    if(dataCapacity[mid] > num) scg(mid+1, e, num);
    return 0;
}

vector<int> solution(int n, vector<string> plans, vector<string> clients) {
    vector<int> answer;
    for(int i=0;i<plans.size();i++){
        vector<string> temp = split(plans[i],' ');
        dataCapacity[i] = stoi(temp[0]);
        for(int j=1;j<temp.size();j++){
            service[stoi(temp[j])]=i+1;
            
        }
    }
    for(int i=0;i<clients.size();i++){
        vector<string> temp = split(clients[i],' ');
        int index = -1;
        int check = false;
        for(int j=1;j<temp.size();j++) {
            if (service[stoi(temp[j])] == 0){
                check = true;
                break;
            }
            else if(index < service[stoi(temp[j])]) {
                index = service[stoi(temp[j])];
             
            }
        }
        if(check) {
            answer.push_back(0);
            continue;
        }
        answer.push_back(scg(index, plans.size()-1, stoi(temp[0])));
    }
    return answer;
}

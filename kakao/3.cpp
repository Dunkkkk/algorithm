#include<iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int gyoStoi(string str){
    int len = str.size();
    int sum = 0;
    for (int i = len - 1, p = 1; i >= 0;  i--, p *= 10) {
        str[i] -= 48;
        sum += str[i] * p;
    }
    return sum;
}

vector<int> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;

    vector<int> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(gyoStoi(buffer));
    }

    return result;
}

vector<int> solution(string s, vector<string> times) {
    vector<int> answer;
    vector<int> now = split(s,':');
    vector<int> start = now;
    int isContinue = 1;
    int recentDay = now[2];
    int recentMonth = now[1];
    int recentYear = now[0];
    int countDay = 0;
    for(int i=0;i<times.size();i++){
        vector<int> addDay = split(times[i], ':');
        now[2] += addDay[0];
        now[3] += addDay[1];
        now[4] += addDay[2];
        now[5] += addDay[3];
        if(now[5] > 59){
            now[5] -= 60;
            now[4] += 1;
        }
        if(now[4] > 59){
            now[4] -= 60;
            now[3] += 1;
        }
        if(now[3] > 23){
            now[3] -= 23;
            now[2] += 1;
        }
        if(now[2] > 30){
            now[3] -= 23;
            now[2] += 1;
        }
        if(now[1] > 12){
            now[1] -= 12;
            now[0] += 1;
        }
        if((recentDay == now[2] and recentMonth == now[1] and recentYear == now[0]) or
        (recentDay == now[2] - 1 and recentMonth == now[1] and recentYear == now[0]) or
        (recentDay == 30 and now[2] == 1 and recentMonth == now[1] - 1 and now[0] == recentYear) or
        (recentDay == 30 and now[2] == 1 and recentMonth == 12 and now[1] == 1 and now[0] - 1 == recentYear)){
            recentDay = now[2];
            recentMonth = now[1];
            recentYear = now[0];
        }
        else {
            isContinue = 0;
            recentDay = now[2];
            recentMonth = now[1];
            recentYear = now[0];
        }
        if(i == times.size() - 1) {
            if (now[2] < start[2]) {
                now[1] -= 1;
                now[2] += 30;
            }
            countDay += now[2] - start[2];
            if (now[1] < start[1]) {
                now[0] -= 1;
                now[1] += 12;
            }
            countDay += (now[1] - start[1]) * 30;
            countDay += (now[0] - start[0]) * 360;
        }
    }

    answer.push_back(isContinue);
    answer.push_back(countDay + 1);
    return answer;
}
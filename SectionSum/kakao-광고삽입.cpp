#include <string>
#include <vector>
#include <iostream>

using namespace std;
int ten[6] = {36000, 3600, 600, 60, 10, 1};
vector<int> timeTable;
vector<pair<int, int>> v;

pair<int, int> logToSec(string log) {
    int ans = 0, f, k = 0;
    for (char c: log) {
        if (c >= '0' and c <= '9') {
            ans += ten[k++] * (c - '0');
        } else if (c == '-') {
            f = ans;
            ans = 0;
            k = 0;
        }
    }
    return {f, ans};
}

string iTos(int a) {
    cout<<a;
    string temp;
    int idx = 0, tmp;
    while (a) {
        tmp = a / ten[idx];
        temp += (char) (tmp + '0');
        a = a % ten[idx++];
    }
    return temp;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int length = logToSec(play_time).second;
    int ad_time = logToSec(adv_time).second;
    timeTable.resize(length + 1);
    for (int i = 0; i < logs.size(); i++) {
        pair<int, int> temp;
        temp = logToSec(logs[i]);
        timeTable[temp.first]++;
        timeTable[temp.second + 1]--;
        v.emplace_back(temp);
    }

    for (int i = 1; i < length; i++) {
        timeTable[i] += timeTable[i - 1];
    }

    long long val = 0, max_val;
    int ans = 0;
    for (int i = 0; i <= ad_time; i++) {
        val += timeTable[i];
    }
    max_val = val;
    for (int i = 1; i <= length - ad_time; i++) {
        val += timeTable[i+ad_time] - timeTable[i-1];
        if (val > max_val) {
            max_val = val;
            ans = i;
        }
    }
    
    return iTos(ans);
}


int main() {
    vector<string> v = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29",
                        "01:37:44-02:02:30"};
    cout << solution("02:03:55", "00:14:15", v);
}

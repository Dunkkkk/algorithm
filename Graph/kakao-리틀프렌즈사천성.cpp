#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <iostream>

using namespace std;
struct point{
    pair<int, int> start;
    pair<int, int> end;
};
int se,ga;
vector<string> b;
vector<char> alphabet;
map<char, point> m;


bool canGo(char c) {
    point temp = m[c];
    bool s = true;
    bool e = true;
    for(int i = min(temp.start.first, temp.end.first)+1; i < max(temp.start.first, temp.end.first); i++){
        if(b[i][temp.start.second] != '.') s = false;
        if(b[i][temp.end.second] != '.') e = false;
    }
    for(int i = min(temp.start.second, temp.end.second)+1; i < max(temp.start.second, temp.end.second); i++){
        if(b[temp.start.first][i] != '.') s = false;
        if(b[temp.end.first][i] != '.') e = false;
    }
    if(b[temp.start.first][temp.end.second] != '.' and b[temp.start.first][temp.end.second] != c) s = false;
    if(b[temp.end.first][temp.start.second] != '.' and b[temp.end.first][temp.start.second] != c) e = false;
    return s or e;
}

bool visit[27];
vector<string> realAns;

void dfs(string ans) {
    cout<<ans<<" ";
    if(ans.size() == alphabet.size()) {
        realAns.push_back(ans);
        return;
    }
    for(int i=0;i<alphabet.size();i++){
        if(canGo(alphabet[i]) and visit[alphabet[i] - 'A']) {
            visit[alphabet[i] - 'A'] = true;
            b[m[alphabet[i]].start.first][m[alphabet[i]].start.second] = '.';
            b[m[alphabet[i]].end.first][m[alphabet[i]].end.second] = '.';
            ans.push_back(alphabet[i]);
            dfs(ans);
            ans.pop_back();
            b[m[alphabet[i]].start.first][m[alphabet[i]].start.second] = alphabet[i];
            b[m[alphabet[i]].end.first][m[alphabet[i]].end.second] = alphabet[i];
            visit[alphabet[i] - 'A'] = false;
        }
    }
}


void solve() {
    for(int i=0;i<se;i++){
        for(int j=0;j<ga;j++){
            if (b[se][ga] == '.' or b[se][ga] == '*') continue;
            char c = b[se][ga];
            if (m.count(c) == 1) {
                m[c] = {{m[c].start.first, m[c].start.second},{se,ga}};
            }
            else {
                alphabet.push_back(c);
                m.insert({c, {{se,ga},{0,0}}});
            }
        }
    }
    for(int i=0;i<alphabet.size();i++){
        string temp = "";
        temp.push_back(alphabet[i]);
        if (canGo(alphabet[i])) dfs(temp);
    }
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    se = m;
    ga = n;
    b = board;
    solve();

    sort(realAns.begin(), realAns.end());
    answer = realAns.empty() ? "IMPOSSIBLE" : realAns[0];
    return answer;
}
//#include <string>
//#include <vector>
//#include <queue>
//#include <iostream>
//
//using namespace std;
//vector<int> g[20001];
//int dist[20001];
//
//
//int solution(int n, vector<vector<int>> edge) {
//    int answer = 0;
//    for(int i=0;i<edge.size();i++){
//        g[edge[i][0]].push_back(edge[i][1]);
//        g[edge[i][1]].push_back(edge[i][0]);
//    }
//    queue<int> q;
//    for(int a : g[1]){
//        dist[a]++;
//        q.push(a);
//    }
//    while(!q.empty()){
//        int f = q.front();
//        q.pop();
//        cout<<f<<" ";
//        for(int a : g[f]){
//            if(dist[a] == 0 and a != 1){
//                dist[a] = dist[f] + 1;
//                q.push(a);
//            }
//        }
//    }
//    for(int i =1;i<=n;i++){
//        cout<<dist[i]<<" ";
//    }
//    int temp = 0;
//    for(int i=1;i<=n;i++){
//        if(temp < dist[i]) {
//            answer = 1;
//            temp = dist[i];
//        }
//        else if (temp == dist[i]) answer++;
//    }
//    return answer;
//}

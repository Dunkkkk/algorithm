////#include <iostream>
////#include <vector>
////#include <utility>
////#include <queue>
////#include <stack>
////#include <algorithm>
////
////using namespace std;
////struct location {
////    int y;
////    int x;
////    int dist;
////};
////int board[52][52];
////vector<location> virus;
////
////int dirx[4] = {0,0,-1,1};
////int diry[4] = {-1,1,0,0};
////
////int n,m;
////int answer = 2147483647;
////stack<location> q;
////int visit[52][52];
////
////
////void printall(){
////    for(int i=0;i<n;i++){
////        for(int j=0;j<n;j++){
////            cout<<visit[i][j]<<" ";
////        }
////        cout<<endl;
////    }
////}
////
////void input() {
////    cin>>n>>m;
////    for(int i=0;i<n;i++){
////        for(int j=0;j<n;j++){
////            cin>>board[i][j];
////            if(board[i][j] == 1) board[i][j] = -100;
////            if(board[i][j] == 0) board[i][j] = -1;
////            if(board[i][j] == 2) {
////                virus.push_back({i,j,0});
////                board[i][j] = -1;
////            }
////        }
////    }
////}
////
////void copyBoard(){
////    for(int i=0;i<n;i++){
////        for(int j=0;j<n;j++){
////            visit[i][j] = board[i][j];
////        }
////    }
////}
////
////
////bool isSize(int y, int x){
////    return x>=0 and x<n and y>=0 and y<n;
////}
////
////int bfs(){
////    queue<location> qu;
////    stack<location> tmp = q;
////    while(!tmp.empty()){
////        qu.push(tmp.top());
////        tmp.pop();
////    }
////    copyBoard();
////    //printall();
////    int ans = 0;
////    while(!qu.empty()){
////        location f = qu.front();
////        qu.pop();
////        //cout<<f.y<<" "<<f.x<<" "<<f.dist<<"\n";
////        ans = max(ans, f.dist);
////        for(int i=0;i<4;i++){
////            int ny = f.y + diry[i];
////            int nx = f.x + dirx[i];
////            if(isSize(ny,nx) and visit[ny][nx] == -1){
////                visit[ny][nx] = f.dist+1;
////                qu.push({ny,nx,f.dist+1});
////            }
////        }
////    }
////    return ans;
////}
////
////int check(){
////    int temp = 0;
////    bool check = false;
////    for(int i=0;i<n;i++){
////        for(int j=0;j<n;j++){
////            if(visit[i][j] == -1) check = true;
////            temp = max(temp, visit[i][j]);
////        }
////    }
////    return check ? -1 : temp;
////}
////
////
////void run(int index) {
////    if(q.size() == m){
////        bfs();
//////        printall();
//////        cout<<"----------------------------------------------------\n";
////        int tmp = check();
////        if(tmp != -1) answer = min(answer, tmp);
////    }
////    else if(index == virus.size()) return;
////    else if(q.size() != m) {
////        board[virus[index].y][virus[index].x] = 0;
////        q.push(virus[index]);
////        run(index + 1);
////        board[virus[index].y][virus[index].x] = -1;
////        q.pop();
////        run(index + 1);
////    }
////}
////
////
////
////
////int main(){
////    input();
////    run(0);
////    answer = answer == 2147483647 ? -1 : answer;
////    cout<< answer;
////}
////
//// Created by 이승철 on 2022/09/27.
////
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <climits>
//#include <algorithm>
//
//#define MAX 51
//using namespace std;
//int map[MAX][MAX], copied_map[MAX][MAX], N, M, ans = INT32_MAX;
//int dr[4] = {-1, 0, 1, 0};
//int dc[4] = {0, 1, 0, -1};
//bool isUsed[11];
//vector<pair<int, int>> virus;
//queue<pair<int, int>> Q;
//
//void input() {
//    cin >> N >> M;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cin >> map[i][j];
//            if (map[i][j] == 2) {
//                map[i][j] = 0;
//                virus.emplace_back(i, j);
//            }
//        }
//    }
//}
//
//void copy_map() {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (map[i][j] == 1)
//                copied_map[i][j] = -1; // 벽
//            else
//                copied_map[i][j] = -2; // 비방문
//        }
//    }
//    for (int i = 0; i < virus.size(); i++) {
//        if (isUsed[i]) {
//            copied_map[virus[i].first][virus[i].second] = 0;
//            Q.push({virus[i].first, virus[i].second});
//        }
//    }
//}
//
//void bfs() {
//    while (!Q.empty()) {
//        auto cur = Q.front();
//        Q.pop();
//
//        for (int i = 0; i < 4; i++) {
//            int nr = cur.first + dr[i];
//            int nc = cur.second + dc[i];
//
//            if (nr < 0 || nr >= N || nc < 0 || nc >= N || copied_map[nr][nc] == -1)
//                continue;
//            if (copied_map[nr][nc] != -2)
//                continue;
//
//            copied_map[nr][nc] = copied_map[cur.first][cur.second] + 1;
//            Q.push({nr, nc});
//        }
//    }
//}
//
//void find_time() {
//    int max_cur_time = 0;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (copied_map[i][j] == -2)
//                return;
//            max_cur_time = max(max_cur_time, copied_map[i][j]);
//        }
//    }
//    ans = min(ans, max_cur_time);
//}
//
//
//void back_tracking(int cnt, int idx) {
//    if(cnt == M){
//        copy_map();
//        bfs();
//        find_time();
//    }
//    else if(idx == virus.size()) return;
//    else if(virus.size() > cnt) {
//        back_tracking(cnt, idx + 1);
//        isUsed[idx] = true;
//        back_tracking(cnt + 1, idx + 1);
//        isUsed[idx] = false;
//    }
//}
//
//
////void back_tracking(int cnt, int idx) {
////    if (cnt == M) {
////        copy_map();
////        bfs();
////        find_time();
////        return;
////    }
////    else if(cnt){
////
////    }
////    else {
////
////    }
////}
//
//int main() {
//    input();
//    back_tracking(0,0);
//    ans == INT32_MAX ? cout << -1 : cout << ans;
//}
//
//
// Created by 이승철 on 2022/09/27.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#define MAX 51
using namespace std;
int map[MAX][MAX], copied_map[MAX][MAX], N, M, ans = INT32_MAX;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool isUsed[11];
vector<pair<int, int>> virus;
queue<pair<int, int>> Q;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                map[i][j] = 0;
                virus.emplace_back(i, j);
                
            }
        }
    }
    cout<<virus.size()<<"---------------------------\n";
}

void copy_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1)
                copied_map[i][j] = -1; // 벽
            else
                copied_map[i][j] = -2; // 비방문
        }
    }
    for (int i = 0; i < virus.size(); i++) {
        if (isUsed[i]) {
            copied_map[virus[i].first][virus[i].second] = 0;
            Q.push({virus[i].first, virus[i].second});
        }
    }
}

void bfs() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N || copied_map[nr][nc] == -1)
                continue;
            if (copied_map[nr][nc] != -2)
                continue;

            copied_map[nr][nc] = copied_map[cur.first][cur.second] + 1;
            Q.push({nr, nc});
        }
    }
}

void find_time() {
    int max_cur_time = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (copied_map[i][j] == -2)
                return;
            max_cur_time = max(max_cur_time, copied_map[i][j]);
        }
    }
    ans = min(ans, max_cur_time);
}
int tmp = 0;
void back_tracking(int cnt) {
    cout<<cnt<<"a";
    if (cnt == M) {
        cout<<tmp++<<"\n";
        copy_map();
        bfs();
        find_time();
        return;
    }
    for (int i = cnt; i < virus.size(); i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            back_tracking(cnt + 1);
            isUsed[i] = false;
        }
    }
}
1 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    back_tracking(0);
    ans == INT32_MAX ? cout << -1 : cout << ans;
}


0


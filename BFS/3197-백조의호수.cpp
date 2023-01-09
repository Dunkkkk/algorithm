//
// Created by changgyo seo on 2023/01/09.
//
#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#define pqType pair<int, pair<int, int>>


using namespace std;

string map[1501];
int n,m;
pair<int, int> startPoint = {-1,-1};
pair<int, int> endPoint;
bool visit[1501][1501];
int dist[1501][1501];
int dirY[4] = {-1,1,0,0};
int dirX[4] = {0,0,-1,1};

bool isSize(int y, int x){
    return x>=0 and x<m and y>= 0 and y<n;
}

int foundDistance(){
    priority_queue<pqType> pq;
    pq.push({0,startPoint});
    visit[startPoint.first][startPoint.second] = true;
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++) {
//            cout<<dist[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    while(!pq.empty()){

        pqType current = pq.top();
        pq.pop();
        //cout<<-current.first<<" "<<current.second.first<<" "<<current.second.second<<endl;
        if(current.second == endPoint) return -current.first;

        for(int i=0;i<4;i++){
            int ny = current.second.first + dirY[i];
            int nx = current.second.second + dirX[i];
            if(isSize(ny,nx) and !visit[ny][nx]) {
                visit[ny][nx] = true;
                pq.push({-current.first > dist[ny][nx] ? current.first : -dist[ny][nx], {ny,nx}});
            }
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        string temp;
        cin>>temp;
        map[i] = temp;
        for(int j=0;j<m;j++) {
            if(temp[j] == 'L' and startPoint.first == -1) startPoint = {i,j};
            else if(temp[j] == 'L') endPoint = {i,j};
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(map[i][j] == 'X') dist[i][j] = 50001;
            else dist[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(map[i][j] == 'X') {
                int mini = 5000;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dirY[k];
                    int nx = j + dirX[k];

                    if (isSize(ny, nx)) {
                        //cout<<ny<<" "<<nx<<" "<<dist[ny][nx] <<endl;
                        mini = mini > dist[ny][nx] + 1 ? dist[ny][nx] + 1 : mini ;
                    }
                    //cout<<mini<<endl;

                }
                dist[i][j] = mini;
            }
        }
    }
    for(int i=n-1;i>=0;i--) {
        for(int j=m-1;j>=0;j--) {
            if(map[i][j] == 'X') {
                int mini = 5000;
                for (int k = 3; k >=0 ; k--) {
                    int ny = i + dirY[k];
                    int nx = j + dirX[k];

                    if (isSize(ny, nx)) {
                        //cout<<ny<<" "<<nx<<" "<<dist[ny][nx] <<endl;
                        mini = mini > dist[ny][nx] + 1 ? dist[ny][nx] + 1 : mini ;
                    }
                    //cout<<mini<<endl;
                }
                dist[i][j] = mini;
            }
        }
    }

    cout<<foundDistance();
}
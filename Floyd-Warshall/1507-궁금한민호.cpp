//
// Created by changgyo seo on 2022/12/26.
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define MAX 2147483647

using namespace std;

int n;
int dist[21][21];
vector<pair<int, pair<int, int>>> arr;
long long newDist[21][21];
int answer;
bool visit[21];
int totalCount;

bool makeNewDistArray(pair<int, pair<int, int>> item){
    int start = item.second.first;
    int end = item.second.second;
    int currnetDist = item.first;
    if(!visit[start]) totalCount--;
    if(!visit[end]) totalCount--;
    visit[start] = true;
    visit[end] = true;

    for(int k=1;k<=n;k++){
        if(newDist[start][end] >= newDist[start][k] + newDist[k][end]) {
            newDist[start][end] = newDist[start][k] + newDist[k][end];
            newDist[end][start] = newDist[start][k] + newDist[k][end];
        }
    }
    if(newDist[start][end] > currnetDist) answer += currnetDist;
    if(newDist[start][end] < currnetDist) { answer = -1; return false;}
    newDist[start][end] = currnetDist;
    newDist[end][start] = currnetDist;
    return true;
   // cout<<start<<" "<<end<<" "<<" "<<currnetDist<<" "<<answer<<"\n";
}


int main(){
    cin>>n;
    totalCount = n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            newDist[i][j] = MAX;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dist[i][j];
            if(i < j) {
                arr.push_back({dist[i][j], {i,j}});
            }
        }
    }
    sort(arr.begin(), arr.end());
    for(pair<int, pair<int, int>> item : arr){
        if(!makeNewDistArray(item)) break;
    }

//    for(int i=1;i<=n;i++){
//        for(int j=i;j<=n;j++){
//            //if(newDist[i][j] != MAX) answer += newDist[i][j];
//            long long temp = newDist[i][j] == MAX ? 0 : newDist[i][j];
//            cout<<temp<<" ";
//        }
//        cout<<endl;
//    }
    cout << answer;
}
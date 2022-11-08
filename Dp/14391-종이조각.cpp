#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int ga,se;
int board[5][5];
bool check[5][5];


void input() {
    cin>>se>>ga;
    for(int i=0;i<se;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<ga;j++){
            board[i][j] = temp[j] - '0';
        }
    }
}

pair<int,int> findNext(int y,int x){
    for(int i=0;i<se;i++){
        for(int j=0;j<ga;j++){
            if(!check[i][j]) return {i,j};
        }
    }
    return {-1,-1};
}

bool isSize(int y,int x){
    return x>=0 and x<ga and y>=0 and y<se;
}
int total = 0;
//0 ga, 1 se
void dfs(int y, int x, int dir ,int ans, vector<int> numberSet) {
    if(y==-1 and x==-1) {
        int temp = 0;
        //cout<<"{";
        for(int a : numberSet) {
            temp += a;
         //   cout<<a<<", ";
        }
        //cout<<"}\n";
        total = max(total, temp);
        return;
    }
    //number end
    int temp = ans * 10 + board[y][x];
    numberSet.push_back(temp);
    pair<int, int> tmp = findNext(y, x);
    check[tmp.first][tmp.second] = true;
    dfs(tmp.first, tmp.second, 2, 0, numberSet);
    numberSet.pop_back();
    check[tmp.first][tmp.second] = false;
    //number continue
    if(dir == 0 or dir == 2){
        if(isSize(y, x+1) and !check[y][x+1]){
            check[y][x+1] = true;
            dfs(y, x+1, 0, ans * 10 + board[y][x], numberSet);
            check[y][x+1] = false;
            
        }
    }
    if(dir == 1 or dir == 2) {
        if(isSize(y+1, x) and !check[y+1][x]){
            check[y+1][x] = true;
            dfs(y+1, x, 1, ans * 10 + board[y][x], numberSet);
            check[y+1][x] = false;
        }
    }
}

int main() {
    input();
    vector<int> v;
    check[0][0]=true;
    dfs(0, 0, 2, 0, v);
    cout<<total;
}

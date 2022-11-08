#include <iostream>
#include <vector>
#include <utility>
#define MAX 2147483647

using namespace std;
struct cctv {
    char type;
    int y;
    int x;
};

int maxY, maxX;
char board[100][100];
vector<cctv> cctvs;


void boardcout(){
    for(int i=0;i<maxY;i++){
        for(int j=0;j<maxX;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"------------------------------------------------------------\n";
}

bool isSize(int y, int x){
    return x>=0 and x<maxX and y>=0 and y<maxY;
}

void input() {
    cin>>maxY>>maxX;
    for(int i=0;i<maxY;i++){
        for(int j = 0; j<maxX;j++){
            cin>>board[i][j];
            if(board[i][j] != '6' and board[i][j] != '0') cctvs.push_back({board[i][j], i, j});
        }
    }
    //cout<<"------------------------------------------------------------\n";
}

int howMany(){
    int c = 0;
    for(int i=0;i<maxY;i++){
        for(int j = 0; j<maxX;j++){
            if(board[i][j] == '0') c++;
        }
    }
    //if(c==3) boardcout();
    return c;
}

void up(int y,int x, char id, bool erase){
    if(!erase){
        for(int i=1;i<maxY;i++){
            if(isSize(y-i, x) and board[y-i][x] == '6') break;
            if(isSize(y-i, x) and board[y-i][x] == '0') board[y-i][x] = id;
        }
    }
    else {
        for(int i=1;i<maxY;i++){
            if(isSize(y-i, x) and board[y-i][x] == '6') break;
            if(isSize(y-i, x) and board[y-i][x] == id) board[y-i][x] = '0';
        }
    }
}

void down(int y,int x, char id, bool erase){
    if(!erase){
        for(int i=1;i<maxY;i++){
            if(isSize(y+i, x) and board[y+i][x] == '6') break;
            if(isSize(y+i, x) and board[y+i][x] == '0') board[y+i][x] = id;
        }
    }
    else{
        for(int i=1;i<maxY;i++){
            if(isSize(y+i, x) and board[y+i][x] == '6') break;
            if(isSize(y+i, x) and board[y+i][x] == id) board[y+i][x] = '0';
        }
    }
}

void left(int y,int x, char id, bool erase){
    if(!erase){
        for(int i=1;i<maxX;i++){
            if(isSize(y, x-i) and board[y][x-i] == '6') break;
            if(isSize(y, x-i) and board[y][x-i] == '0') board[y][x-i] = id;
        }
    }
    else {
        for(int i=1;i<maxX;i++){
            if(isSize(y, x-i) and board[y][x-i] == '6') break;
            if(isSize(y, x-i) and board[y][x-i] == id) board[y][x-i] = '0';
        }
    }
}
void right(int y,int x, char id, bool erase){
    if(!erase){
        for(int i=1;i<maxX;i++){
            if(isSize(y, x+i) and board[y][x+i] == '6') break;
            if(isSize(y, x+i) and board[y][x+i] == '0') board[y][x+i] = id;
        }
    }
    else {
        for(int i=1;i<maxX;i++){
            if(isSize(y, x+i) and board[y][x+i] == '6') break;
            if(isSize(y, x+i) and board[y][x+i] == id) board[y][x+i] = '0';
        }
    }
}

int answer = MAX;

void dfs(int index){
    //if(cctvs.empty()) answer = howMany();
    if(index == cctvs.size()) {
        answer = min(answer, howMany());
        return;
    }

    cctv now = cctvs[index];
    switch (now.type) {
        case '1':
            up(now.y,now.x,'A' + index, false);
            dfs(index+1);
            up(now.y,now.x,'A' + index, true);
            
            down(now.y,now.x,'A' + index, false);
            dfs(index+1);
            down(now.y,now.x,'A' + index, true);
            
            left(now.y,now.x,'A' + index, false);
            dfs(index+1);
            left(now.y,now.x,'A' + index, true);
            
            right(now.y,now.x,'A' + index, false);
            dfs(index+1);
            right(now.y,now.x,'A' + index, true);
            break;
        case '2':
            right(now.y,now.x,'A' + index, false);
            left(now.y,now.x,'A' + index, false);
            dfs(index+1);
            right(now.y,now.x,'A' + index, true);
            left(now.y,now.x,'A' + index, true);
            
            up(now.y,now.x,'A' + index, false);
            down(now.y,now.x,'A' + index, false);
            dfs(index+1);
            up(now.y,now.x,'A' + index, true);
            down(now.y,now.x,'A' + index, true);
            break;
        case '3':
            right(now.y,now.x,'A' + index, false);
            up(now.y,now.x,'A' + index, false);
            dfs(index+1);
            right(now.y,now.x,'A' + index, true);
            up(now.y,now.x,'A' + index, true);
            
            up(now.y,now.x,'A' + index, false);
            left(now.y,now.x,'A' + index, false);
            dfs(index+1);
            left(now.y,now.x,'A' + index, true);
            up(now.y,now.x,'A' + index, true);
            
            down(now.y,now.x,'A' + index, false);
            left(now.y,now.x,'A' + index, false);
            dfs(index+1);
            down(now.y,now.x,'A' + index, true);
            left(now.y,now.x,'A' + index, true);
            
            down(now.y,now.x,'A' + index, false);
            right(now.y,now.x,'A' + index, false);
            dfs(index+1);
            down(now.y,now.x,'A' + index, true);
            right(now.y,now.x,'A' + index, true);
            break;
        case '4':
            up(now.y,now.x,'A' + index, false);
            right(now.y,now.x,'A' + index, false);
            left(now.y,now.x,'A' + index, false);
            dfs(index+1);
            up(now.y,now.x,'A' + index, true);
            right(now.y,now.x,'A' + index, true);
            left(now.y,now.x,'A' + index, true);
            
            down(now.y,now.x,'A' + index, false);
            right(now.y,now.x,'A' + index, false);
            left(now.y,now.x,'A' + index, false);
            dfs(index+1);
            down(now.y,now.x,'A' + index, true);
            right(now.y,now.x,'A' + index, true);
            left(now.y,now.x,'A' + index, true);
            
            right(now.y,now.x,'A' + index, false);
            up(now.y,now.x,'A' + index, false);
            down(now.y,now.x,'A' + index, false);
            dfs(index+1);
            right(now.y,now.x,'A' + index, true);
            up(now.y,now.x,'A' + index, true);
            down(now.y,now.x,'A' + index, true);
            
            left(now.y,now.x,'A' + index, false);
            up(now.y,now.x,'A' + index, false);
            down(now.y,now.x,'A' + index, false);
            dfs(index+1);
            left(now.y,now.x,'A' + index, true);
            up(now.y,now.x,'A' + index, true);
            down(now.y,now.x,'A' + index, true);
            break;
        case '5':
            right(now.y,now.x,'A' + index, false);
            up(now.y,now.x,'A' + index, false);
            down(now.y,now.x,'A' + index, false);
            left(now.y,now.x,'A' + index, false);
            dfs(index+1);
            right(now.y,now.x,'A' + index, true);
            up(now.y,now.x,'A' + index, true);
            down(now.y,now.x,'A' + index, true);
            left(now.y,now.x,'A' + index, true);
            break;
        default:
            break;
    }
}

int main() {
    input();
    dfs(0);
    cout<<answer;
}


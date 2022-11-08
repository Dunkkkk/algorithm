#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
struct load {
    int startY;
    int startX;
    int endY;
    int endX;
    //0 ga 1 se;
    int dir;
    
};
vector<load> v;
int n;

load check(load a){
    for(int i=0;i<v.size();i++) {
        if(a.dir == 0 and v[i].dir == 0){
            if((a.startX <= v[i].startX and v[i].startX <= a.endX) or (a.startX <= v[i].endX and v[i].endX <= a.endX)){
                return v[i];
            }
        }
        else if (a.dir == 0 and v[i].dir == 1){
            if(a.startX <= v[i].startX and v[i].startX <= a.endX and v[i].startY <= a.startY and a.startY <= v[i].endY ){
                return v[i];
            }
        }
        else if(a.dir == 1 and v[i].dir == 0){
            if(v[i].startX <= a.startX and a.startX <= v[i].endX and a.startY <= v[i].startY and v[i].startY <= a.endY ){
                return v[i];
            }
        }
        else {
            if((a.startY <= v[i].startY and v[i].startY <= a.endY) or (a.startY <= v[i].endY and v[i].endY <= a.endY)){
                return v[i];
            }
        }
    }
    return {0,0,0,0};
}

bool isOkay(load a){
    return a.startX == 0 and a.endX == 0 and a.startY == 0 and a.endY == 0;
}

int outTime(load a, load b){
    if(a.dir == 0 and b.dir == 0){
        if(a.startX <= b.startX) return abs(a.endX - b.startX);
        else return abs(a.endX - b.endX);
    }
    else if (a.dir == 0 and b.dir == 1){
        if(a.startX <= b.startX) return abs(a.startX - b.startX);
        else return abs(a.endX-b.startX);
    }
    else if(a.dir == 1 and b.dir == 0){
        if(a.startY <= b.startY) return abs(a.startY - b.startY);
        else return abs(a.endY-b.startY);
    }
    else {
        if(a.startY <= b.startY) return abs(a.endY - b.startY);
        else return abs(a.endY - b.endY);
    }
}


int input(){
    int startx = 0;
    int starty = 0;
    int endx = 0;
    int endy = 0;
    //up 1 down 2 left 3 right 4
    int currentDir=4;
    int m;
    int ans = 0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int t;
        char dir;
        cin>>t>>dir;
        if(currentDir == 1){
            ans += t;
            endy = starty - t;
            load temp = {starty, startx, endy,endx , 1};
            load result = check(temp);
            
            if(!isOkay(result)){
                ans -=outTime(temp, result);
                currentDir = 5;
            }
            else {
                if(dir == 'L'){
                    currentDir = 3;
                    startx = endx;
                    starty = endy;
                }
                else{
                    currentDir = 4;
                    startx = endx;
                    starty = endy;
                }
            }
        }
        else if(currentDir == 2){
            ans += t;
            endy = starty + t;
            load temp = {starty, startx, endy,endx , 1};
            load result = check(temp);
            
            if(!isOkay(result)){
                ans -=outTime(temp, result);
                currentDir = 5;
            }
            else {
                if(dir == 'L'){
                    currentDir = 4;
                    startx = endx;
                    starty = endy;
                }
                else{
                    currentDir = 3;
                    startx = endx;
                    starty = endy;
                }
            }
        }
        else if(currentDir == 3){
            ans += t;
            endx = startx - t;
            load temp = {starty, startx, endy,endx , 0};
            load result = check(temp);
            
            if(!isOkay(result)){
                ans -=outTime(temp, result);
                currentDir = 5;
            }
            else {
                if(dir == 'L'){
                    currentDir = 2;
                    startx = endx;
                    starty = endy;
                }
                else{
                    currentDir = 1;
                    startx = endx;
                    starty = endy;
                }
            }
        }
        else if(currentDir == 4){
            ans += t;
            endx = startx + t;
            load temp = {starty, startx, endy,endx , 0};
            load result = check(temp);
            
            if(!isOkay(result)){
                ans -=outTime(temp, result);
                currentDir = 5;
            }
            else {
                if(dir == 'L'){
                    currentDir = 1;
                    startx = endx;
                    starty = endy;
                }
                else{
                    currentDir = 2;
                    startx = endx;
                    starty = endy;
                }
            }
        }
    }
    return ans;
}



int main() {
    cout<<input();
}

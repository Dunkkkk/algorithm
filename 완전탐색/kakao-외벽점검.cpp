#include <string>
#include <vector>
#include <algorithm>
#include <iostream>>

using namespace std;
int number;
vector<int> wall;
vector<int> person;
bool isUsed[10];
int usedCount;


// 8번
int findNear(int dist){
    for(int i=0;i<person.size();i++) if(person[i] > dist and !isUsed[i]) return i;
    return -1;
}


int dfs(int index, int startIndex, int chance){
    if(index == startIndex and chance == 0) return 1;
    
    int answer = 100;
    int finish = (startIndex - 1) < 0 ? number - 1 : startIndex - 1;
    //cout<<index<<" "<<finish;
    for(int i=index;i != finish; i += i == number - 1 ? - (number - 1) : 1){
        int idx;
        if(i == index) {
            idx = findNear(0);
        }
        else {
            idx = wall[index] > wall[i] ? findNear(number - wall[index] + wall[i]) : findNear(wall[i] - wall[index]);
        }
        if(idx == -1) break;
        else {
            isUsed[idx] = true;
            cout<<index<<" "<<i<<endl;
            answer = min(dfs(i+1,startIndex,0) + 1, answer);
            isUsed[idx] = false;
        }
    }
    return answer;
}


int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 2147483647;
    number = n; wall = weak;
    sort(dist.begin(), dist.end());
    person = dist;
    for(int i=0;i<weak.size();i++){
        int tmp = dfs(i,i,1);
        answer = min(tmp, answer);
        cout<<tmp<<"-------------------------------\n";
    }
    return answer;
}

int main(){
    vector<int> w= {1, 5, 6, 10};
    vector<int> d= {1, 2, 3, 4};
    int nn = 12;
    solution(nn, w, d);
}

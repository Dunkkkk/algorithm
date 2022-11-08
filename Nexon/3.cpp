#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int answer = 0;

vector<int> v;
priority_queue<int, vector<int>, greater<int>> q;

void print(){
    queue<int> tttt;
    cout<<"---------------\n";
    cout<<q.size()<<endl;
    cout<<"---------------\n";
    for(int i=0;i<q.size();i++){
        cout<<q.top()<<" ";
        tttt.push(q.top());
        q.pop();
    }
    cout<<endl;
    while(!tttt.empty()){
        q.push(tttt.front());
        tttt.pop();
    }
    cout<<"finish--\n";
}

long getMinimumHealth(vector<int> initial_players, vector<int> new_players, int rank) {
    int n = initial_players.size();
    for(int i=0;i<initial_players.size();i++){
        v.push_back(initial_players[i]);
    }
    sort(v.begin(),v.end());
    answer += v[v.size()-rank];
    int top = v[v.size()-rank];
    for(int i= v.size() - 1; i>=0 ;i--){
        if(q.size() == rank - 1) break;
        q.push(v[i]);
    }
    for(int i=0;i<new_players.size();i++){
        if(new_players[i] >= top){
            q.push(new_players[i]);
           
            top = q.top();
            
            q.pop();
          
        }
        
        
        answer += top;
       
    }
    return answer;
}

int main(){
    vector<int> one = {1,2,5};
    vector<int> two = {2,5,4};
    cout<<getMinimumHealth(one, two, 3);
    
}

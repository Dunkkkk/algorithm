//
// Created by changgyo seo on 2022/11/19.
//
#include<iostream>
#include<stack> // stack<pair<int,int>> 사용
#include<vector> // vector 사용
#include<utility> // pair 사용
#include<algorithm> // sort 사용

using namespace std;

int answer[100001]; // 정답을 담는 배열 1 ≤ 𝑃𝑖 ≤ 1,000,000 사용

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        vector<pair<int,int>> dragons;
        int countDragon;
        cin>>countDragon;
        for(int i=1;i<=countDragon;i++){
            int power;
            cin>>power;
            dragons.push_back({power,i});
        }
        sort(dragons.begin(),dragons.end());
        stack<int> s;

        for(pair<int,int> dragon : dragons){
            int canEatThisFloor = -1;
            while(!s.empty() and canEatThisFloor == -1) {
                if(s.top() > dragon.second) s.pop();
                else canEatThisFloor = s.top();
            }
            answer[dragon.second] = canEatThisFloor;
            s.push(dragon.second);
        }
        for(int i=1;i<=countDragon;i++){
            cout<<answer[i]<<" ";
        }
        cout<<"\n";
    }
}
//
// Created by changgyo seo on 2022/12/24.
//
#include<iostream>
#include<map>
#include<vector>

using namespace std;

int pSum[1000000];
vector<int> arr;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int d,n;
        cin>>d>>n;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            pSum[sum % d]++;
        }
        long long answer = 0;
        sum = 0;
        answer += pSum[0];
        for(int i=0;i<n;i++){
            sum += arr[i];
            answer += pSum[sum % d] != 0 ? --pSum[sum % d] : 0;
        }
        cout<<answer<<"\n";
        answer = 0;
        arr.clear();
        for(int i=0;i<d;i++){
            pSum[i] = 0;
        }
    }
}
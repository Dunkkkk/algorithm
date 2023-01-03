#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
vector<int> numbers;

void makePermutationAndSolve(int x, int start, int end){
    long long answer = 0;
    int answerCount = 0;
    long long multi = 1;
    sort(numbers.begin(), numbers.end());
    do {
        answer = 0;
        multi = 1;
        for(int i=0; i<numbers.size();i++) {
            answer += numbers[i] * multi;
            multi *= x;
        }
        if((answer % 1013) >= start and (answer % 1013) <= end) answerCount++;
    }while(next_permutation(numbers.begin(), numbers.end()));

    cout<<answerCount<<"\n";
}

void input(){
    int tc;
    cin>>tc;
    while(tc--) {

        int n, start, end, x;
        cin>>n;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            numbers.push_back(temp);
        }
        cin>>start>>end>>x;
        makePermutationAndSolve(x,start,end);
        numbers.clear();
    }
}


int main(){
    input();
}
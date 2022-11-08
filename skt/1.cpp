#include <string>
#include <vector>

using namespace std;
int ans[10001];


vector<int> solution(vector<int> p) {
    vector<int> answer;
    int n = p.size();
    for(int i=0;i<n;i++){
        int min = p[i];
        int index = i;
        for(int j=i;j<n;j++){
            if(min > p[j]) {
                min = p[j];
                index = j;
            }
        }
        if(index != i){
            ans[i]++;
            ans[index]++;
            int temp = p[i];
            p[i] = p[index];
            p[index] = temp;
        }
    }
    
    for(int i=0;i<p.size();i++){
        answer.push_back(ans[i]);
    }
    return answer;
}

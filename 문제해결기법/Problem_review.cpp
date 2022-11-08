#include <iostream>
#include <queue>
#include <map>

using namespace std;

priority_queue<int, vector<int>, greater<int>> minq;
priority_queue<int, vector<int>, less<int>> maxq;
map<int, int> isCount;
int n,m;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while (tc--) {
        while(!maxq.empty()) maxq.pop();
        while(!minq.empty()) minq.pop();
        isCount.clear();
        cin>>n>>m;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            isCount[a]++;
            minq.push(a);
            maxq.push(a);
        }
        for(int i=0;i<m;i++){
            string a;
            cin>>a;
            if(a[0] == 'D'){
                cin>>a;
                if(a[1] == 'a'){
                    while (!maxq.empty() && isCount[maxq.top()] == 0) maxq.pop();
                    if (!maxq.empty()) {
                        isCount[maxq.top()]--;
                        maxq.pop();
                    }
                }
                else {
                    while (!minq.empty() && isCount[minq.top()] == 0) minq.pop();
                    if (!minq.empty()) {
                        isCount[minq.top()]--;
                        minq.pop();
                    }
                }
            }
            else {
                int b;
                cin>>b;
                isCount[b]++;
                minq.push(b);
                maxq.push(b);
            }
        }
        
        while (!maxq.empty() && isCount[maxq.top()] == 0) maxq.pop();
        while (!minq.empty() && isCount[minq.top()] == 0) minq.pop();
        cout << minq.top() << " " << maxq.top() << "\n";
    }
}

int main() {
    input();
}

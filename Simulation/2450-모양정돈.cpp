#include <iostream>
#define MAX 2147483647

using namespace std;
struct accumulate {
    int count[4];
};
int n;
int countN[4];
int arr[100002];
accumulate number[100002] = {{0,0,0},};

void input() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        accumulate temp = number[i-1];
        temp.count[arr[i]]++;
        number[i] = temp;
        countN[arr[i]]++;
    }
}

int solve() {
    int ans = MAX;
    ans = min(ans, countN[1] - number[countN[1]].count[1] + number[countN[1] + countN[2] ].count[3]);
    ans = min(ans, countN[1] - number[countN[1]].count[1] + number[countN[1] + countN[3] ].count[2]);
    ans = min(ans, countN[2] - number[countN[2]].count[2] + number[countN[2] + countN[1] ].count[3]);
    ans = min(ans, countN[2] - number[countN[2]].count[2] + number[countN[2] + countN[3] ].count[1]);
    ans = min(ans, countN[3] - number[countN[3]].count[3] + number[countN[3] + countN[1]].count[2]);
    ans = min(ans, countN[3] - number[countN[3]].count[3] + number[countN[3] + countN[2] ].count[1]);
    return ans;
}

int main() {
    input();
    cout<<solve();
}

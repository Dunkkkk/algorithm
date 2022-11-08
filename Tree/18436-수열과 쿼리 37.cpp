#include <iostream>

using namespace std;
struct counting {
    int even; // 짝수
    int odd;  // 홀수
};
int arr[262144];
counting tree[262144];
int idx[100001];
int n,m;

counting makeTree(int start, int end,int index){
    if(start==end) {
        idx[start] = index;
        if(arr[start] % 2 == 0) return {1,0};
        return {0,1};
    }
    int mid = (start+end)/2;
    counting left = makeTree(start,mid,index*2);
    counting right = makeTree(mid+1,end,index*2+1);
    return tree[index] = {left.even + right.even, left.odd + right.odd};
}

void updateTree(int start,int end, int index, int node, int number){
    if(index<start || index>end) return;
    if(number % 2 == 0) {
        tree[node].even++;
        tree[node].odd--;
    }
    else {
        tree[node].even--;
        tree[node].odd++;
    }
    if(start==end) return;
    int mid = (start+end)/2;
    updateTree(start,mid,index,node*2,number);
    updateTree(mid+1,end,index,node*2+1,number);
}

counting findTree(int start, int end,int findStart, int findEnd, int index) {
    if(findStart>end || findEnd<start) return {0,0};
    if(findStart<=start && end<=findEnd) return tree[index];
    int mid = (start+end)/2;
    counting left = findTree(start,mid,findStart,findEnd,index*2);
    counting right = findTree(mid+1,end,findStart,findEnd,index*2+1);
    return {left.even + right.even, left.odd + right.odd};
}

void input() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    makeTree(1,n,1);
    while(k--){
        int temp,a,b;
        cin>>temp>>a>>b;
        switch (temp) {
            case 1:
                if((arr[a] % 2) != (b % 2)){
                    updateTree(1,n,idx[a],1,b);
                    arr[a] = b;
                }
                break;
            case 2:
                cout<<findTree(1,n, a, b, 1).even;
                break;
            case 3:
                cout<<findTree(1, n, a, b, 1).odd;
                break;
        }
    }
}

int main() {
    input();
}

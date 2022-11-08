#include <iostream>
#include <algorithm>

using namespace std;

int primeNumber[1000000];
int n, arr[101];

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
}


void find(int start, int end){
    int mid = start + end;
    if (isOkay(mid)){
        
    }
}


int main() {
    
}

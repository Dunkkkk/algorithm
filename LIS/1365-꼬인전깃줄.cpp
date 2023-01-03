//
// Created by changgyo seo on 2022/12/21.
//
#include <iostream>

using namespace std;
int arr[100001];
int cache[100001];
int length;
int n;

int binarySearch(int start, int end, int value){
    if(start == end) return end;
    int mid = start + end / 2;

    if(cache[mid] >= value) return binarySearch(start, mid, value);
    else return binarySearch(mid + 1, end, value);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++){
        int idx = binarySearch(0, length, arr[i]);
        if(cache[idx] == 0 and  cache[idx] > arr[i]) {
            cache[idx] = arr[i];
                
        }
    }
}
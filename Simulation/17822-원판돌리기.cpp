#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int arr[55][55];
int n,m,t;
int sum,c;

void spin(int x, int d, int k){
    if(d == 1){
        //left
        int origin = arr[x][0];
        int idx = 0;
        for(int i=0;i<m;i++){
            if(i == m-1) {
                arr[x][idx] = origin;
                break;
            }
            arr[x][idx] = arr[x][(idx+k) % m];
            idx = (idx + k) % m;
        }
    }else {
        //right
        int origin = arr[x][0];
        int idx = 0;
        for(int i=0;i<m;i++){
            if(i == m-1) {
                arr[x][idx] = origin;
                break;
            }
            arr[x][idx] = arr[x][(idx-k) % m];
            idx = (idx - k) % m;
        }
    }
}

void find(int x,int d, int k){
    for(int i=0;i<n;i++){
        if( (i+1) % x == 0){
            spin(i,d,k);
        }
    }
    
    vector<pair<int,int>> temp;
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            int ans = arr[x][y];
            if( ans == 0) continue;
            if(arr[x][(y+1)% m] == ans){
                temp.push_back({x,(y+1)% m});
            }
            if(arr[x][(y-1)% m] == ans){
                temp.push_back({x,(y-1)% m});
            }
            if(x+1 < n){
                if(arr[(x+1)][y] == ans){
                    temp.push_back({x+1,y});
                }
            }
            if(x-1 >= 0){
                if(arr[x-1][y] == ans){
                    temp.push_back({x-1,y});
                }
            }
        }
    }
    if(temp.empty()){
        float tmp = sum / c;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] != 0){
                    if((float)arr[i][j] > tmp) arr[i][j]--;
                    else if((float)arr[i][j] < tmp) arr[i][j]++;
                }
            }
        }
    }
    else {
        for(int i=0;i<temp.size();i++){
            int tmp = arr[temp[i].first][temp[i].second];
            sum -= tmp;
            c--;
            arr[temp[i].first][temp[i].second] = 0;
        }
    }
}



void input(){
    cin>>n>>m>>t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            sum += arr[i][j];
            c++;
        }
     
    }
    for(int i=0;i<t;i++){
        int x,d,k;
        cin>>x>>d>>k;
        find(x,d,k);
    }
}

int main(){
    input();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=arr[i][j];
        }
    }
    cout<<"------------\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j] << "";
        }
        cout<<endl;
    }
 
}

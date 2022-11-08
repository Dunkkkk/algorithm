//
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//int n;
//bool fin = false;
//vector<int> ans;
//vector<int> answer;
//
//void input(){
//    cin>>n;
//}
//
//bool check(int idx){
//    if(ans.size() < i) return true;
//    ans.push_back(i);
//    for(int j=0;j<idx/2;j++){
//        if(ans[idx - idx/2 - j] != ans[idx - j]) {
//            ans.pop_back();
//            return true;
//            
//        }
//    }
//    ans.pop_back();
//    return false;
//}
//
//void solve(int idx){
//
//    if(idx == n and !fin){
//        answer = ans;
//        fin = true;
//        return;
//    }
//    for(int i=1;i<=3;i++){
//        if(!fin and check(i,idx)){
//            ans.push_back(i);
//            solve(idx+1);
//            ans.pop_back();
//        }
//    }
//}
//
//
//int main(){
//    input();
//    solve(0);
//    for(int i=0;i<answer.size();i++){
//        cout<<answer[i];
//    }
//}

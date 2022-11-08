#include <vector>
#include <iostream>
#include <string>

using namespace std;
int prefix_posfix_arr[10001];//접두사 접미사를 닮을 배열
//강의자료에 있는 pseudo code를 바탕으로 구현함

void make_prefix_postfix_arr(string s){//failure function
    prefix_posfix_arr[0] = 0;//failure array의 0번 index는 반드시 0값이 들어감
    int i = 1; //초기화 i는 패턴에 있는 거지만 텍스트로 이해하고 하는 것이 편하므로 텍스트의 인덱스라고 부를 예정
    int j = 0; //초기화 j는 패턴의 인덱스
    while(i< s.size()){ //텍스트의 끝까지 읽어야함
        if(s[i]==s[j]){ //텍스트와 패턴의 문자가 일치한다면
            prefix_posfix_arr[i] = j+1; //패턴의 일치했던 부분의 1을 더해서 해당 인덱스에 넣어준다
            i++; //텍스트 인덱스 증가
            j++; //패턴 인덱스 증가
        }
        else if(j>0){//다르지만 기존에 같았던 값이 있었다면
            j = prefix_posfix_arr[j-1]; // j를 전 인덱스의 값으로 갱신해준다.
        }
        else{
            prefix_posfix_arr[i] = 0; //하나도 같은거이 없는 거라소 걍 0을 넣어준다.
            i++;//그리고 텍스트 인덱스 증가
        }
    }
}

vector<int> kmp(string story, string wishWord){//kmp실행 알고리즘 story는 text, wishword는 pattern으로 생각하면 된다.
    int cur = 0;//현재 인덱스 즉 패턴에 인덱스
    vector<int> step_one;//문제의 중간 답을 저장할 벡터
    vector<int> ans;//return 값을 저장할 벡터
    for(int i = 0;i<story.size();){//텍스트 사이즈만큼 돈다.
        if(story[i] == wishWord[cur]){ //텍스트와 패턴이 같으면
            if (cur == wishWord.size()-1) {//현재의 패턴의 인덱스가 끝까지 왔으면
                ans.push_back(i-cur); //정답에 이번 패턴의 시작 위치를 넣어주고.
                step_one.push_back(cur - prefix_posfix_arr[cur]+1);//원본 패턴의 접두사 접미사 인덱스만큼 skip을 해야하므로
                                                                   //현재 위치에서 인덱스 + 1 만큼 빼준다.
                cur = prefix_posfix_arr[cur] - 1;//다시 패턴인덱스를 수정한다.
            }
            i++;//완전 글자가 다 일치한게 아니면 텍스트 인덱스 증가.
            cur++;//패턴 인덱스 증가
        }
        else if(cur > 0){//다르지만 그전에 몇개가 같았더라면
            int origin = cur; // 현재 패턴 인덱스를 저장하고
            cur = prefix_posfix_arr[cur-1]; // 옮겨야할 인덱스를 넣어준뒤
            step_one.push_back(origin - cur); //그 차만큼 skip하는 것이라서 중간정보 벡터에 넣어준다.
        }
        else{
            step_one.push_back(1);//완전 첨에 틀리면 한칸만 옆으로 가는 것이라서 1만큼 skip한다는 정보 push
            i++;//텍스트 인덱스 증가
        }
    }
    for(int i : step_one) cout<<i<<" "; //넣어놓은 중간정보를 모두 출력한다.
    cout<<"\n";//출력제한 맞추기 위한 개행문자출력
    return ans;//정답 인덱스 벡터를 return
}

int main(){
    string story, wishWord;//두가지 변수선언 텍스트와 패턴
    cin>>story>>wishWord;//입력
    make_prefix_postfix_arr(wishWord);//failure function 실행
    vector<int> step_two = kmp(story, wishWord); //kmp알고리즘을 돌려서 벡터에 저장
    for(int i : step_two) cout<< i <<" "; //정답을 공백을 두고 출력.
}


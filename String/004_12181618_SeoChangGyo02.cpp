#include <vector>
#include <string>
#include <iostream>

using namespace std;
int lastOccrurrenceArr[26];//영어의 총 갯수이 26개의 인덱스를 가진 배열선언
int m,n;//사이즈 저장변수
string text,pattern;//텍스트와 패턴 선언
//강의자료에 있는 pseudo code를 바탕으로 구현함

void input(){
    cin>>text>>pattern;//입력을 받는다
    m = pattern.size();//패턴의 사이즈를 넣는다.
    n = text.size();//텍스트의 사이즈를 넣는다.
}


void lastOccurenceFunction(){//pattern을 가지고 각 글자의 가장큰 인덱스로 초기화하는 함수
    int X = -1; // X, 즉 어떤 문자도 가능한 X의 인덱스를 저장하는 변수
    for(int i = 0; i< 26;i++){//영어문자대로 우선 초기화 한다. 알파벳은 26이다.
        lastOccrurrenceArr[i] = -1; //보어무어알고리즘은 없는 알파벳은 -1로 초기화한다.
    }
    for(int i=0; i < pattern.size(); i++){//패턴의 길이만큼 반복문 인덱스 0부터 시작하기때문에 알아서 가장 큰 인덱스가 담기게된다
        lastOccrurrenceArr[pattern[i] - 'a'] = i;//해당 알파벳의 인덱스를 넣어준다.
        if(pattern[i] == 'X') X = i; //만약 X가 나오면 해당 인덱스를 저장한다.
    }
    for(int i=0;i<26;i++){//알파벳을 돌면서
        if(lastOccrurrenceArr[i] < X) lastOccrurrenceArr[i] = X;//X 즉 모든 알파벳이든 되는 X의 위치보다 낮은 인덱스를 가졌으면
                                                                //X의 인덱스로 갱신한다.
    }
}

vector<int> boyerMooreMatch(){//보어무어알고리즘 실행 함수
    vector<int> ans;//정답의 인덱스를 담을 벡터
    vector<int> step_one;//중간답을 출력할 벡터
    int i = m-1;//텍스트의 시작위치를 패턴의 마지막 인덱스에 위치한다.
    int j = m-1;//j 또한 마찬가지
    while( i <= n-1 ){//텍스트의 끝까지 본다.
        if(text[i] == pattern[j] or pattern[j] == 'X'){ //텍스트와 패턴의 글자가 같거나, 패턴이 X 즉 아무글자나 호응되면
            if(j==0){//패턴을 뒤에서 맨앞에서까지 읽었으면
                ans.push_back(i);//정답인거라서, 답 벡터에 넣는다.
                step_one.push_back(1);//정답이면 전체 패턴을 오른쪽으로 한칸 옮긴다.
                i += m;//패턴의 길이만큼 텍스트의 인덱스를 옮겨준다. 이게 한칸 옮기는 거와 같은 의미
                j = m-1; //j를 다시 맨뒤로 옮긴다
            }
            else {
                j--;//처음이 아니면 패턴인덱스를 줄인다.
                i--;//처음이 아니면 텍스트 \인덱스를 줄인다.
            }
        }
        else{
            int l = lastOccrurrenceArr[text[i] - 'a']; //글자가 매칭이 안됬으면 해당 글자의 인덱스를 뽑아본다.
            if ( j < l ) step_one.push_back(1);//만약 지금 j가 인덱스보다 작으면 한칸 이동한다.
            else step_one.push_back( j - (l));//아니라면 j의 위치로 l을 맞추는 것이므로 j - l을 한다.
            i += m - min(j, l+1); // 둘중에 작은 것만큼 전체 사이즈에서 빼서 i에 더한다.
            j = m - 1;//j는 다시 마지막인덱스를 가르키게 한다.
        }
    }
    for(int i : step_one) cout<<i<<" ";//중간 답을 공백으로 출력한다.
    cout<<"\n";//개행문자.
    return ans;//답 return
}

int main(){
    input();//입력실행 
    lastOccurenceFunction();//알파벳인덱스를 만들어줄 함수 실행
    vector<int> step_two = boyerMooreMatch();//보어무어알고리즘 실행
    for(int i : step_two) cout<<i<<" ";//정답을 공백으로 출력한다.
}


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//모든 배열은 최대값 500000의 길이 이지만, 유저는 1부터 시작하기때문에 500001로 선언한다.
int n,m; //n은 전체 vertex의 수 즉 사용자의 수, m은 팔로우 관계의 갯수
vector<int> arr[500001]; //정상적인 direct graph를 표현하는 인접리스트 ( vector를 통해 구현 )
vector<int> reverse_arr[500001]; // 위에 direct graph의 간선의 방향을 바꾼 graph 코사리주 알고리즘으로 SCC를 구현할 시 필요험
stack<int> s; //정상그래프의 방문이 끝난 순서대로 넣은 스택
int vertexRank[500001]; //팔로워수가 많고, 같을 시 유저 번호가 작은 순으로 배열에 유저의 번호를 넣어놓을 유저의 실행 순위를 저장할 배열
int visit[500001]; //정상 그래프의 방문을 표시할 배열, reverse_arr에선 해당 인덱스의 leader를 저장해 놓을 배열

//배열을 정렬할때 팔로워가 많은 순, 같다면 유저의 번호가 낮은 순대로 비교할 비교함수
bool cmp(int a, int b) {
    if (reverse_arr[a].size() == reverse_arr[b].size()){ // 팔로워수가 같다면
        return a < b; //유저번호가 낮은 값을 반환
    }
    return reverse_arr[a].size() > reverse_arr[b].size(); //팔로워수가 다르다면 팔로워수의 따라 bool값 반환
}


void input(){//변수를 초기화하고 문제에 맞는 정렬을 한다.
    cin>>n>>m; //유저의 수와 유저사이의 관계의 수를 cin을 통해 변수에 저장한다.
    for(int i=0;i<m;i++){ // 관계의 수만큼 반복문을 실행한다.
        int a,b; // 임시  변수 선언
        cin>>a>>b; // a의 유저가 b의 유저를 팔로우한다.
        arr[a].push_back(b); // 정상그래프에 a가 b를 팔로잉한다고 인접리스트에 저장
        reverse_arr[b].push_back(a); //역방향 그래프 즉 a는 b의 팔로워라는 인접리스트에 저장
                                     //여기서 reverse_arr[x].size()는 x의 팔로워 수를 의미
    }
    for(int i=1;i<=n;i++){ // 유저의 수만큼 반복문을 돌린다.
        vertexRank[i] = i; // 유저의 실행 순위를 저장하기위해 각 인덱스를 초기화
        visit[i] = 0; // 방문 여부를 0으로 초기화한다. 불필요하지만 가독성을 위해 적음
        sort(arr[i].begin(), arr[i].end(), cmp); // 정상그래프를 팔로워가 많은 순, 같다면 유저번호 순으로 정렬
    }
   
    sort(vertexRank+1,vertexRank+n+1,cmp);
   
}

void dfs(int x,int version, int leader){ //dfs함수 x는 이번에 방문한 유저 vertex를, version은 정상 그래프탐색인지, 역방향 그래프 탐색인지를
                                         //표시하는 파라미터, leader는 version == 1 즉 역방향 탐색에 이번 탐색의 리더를 표시하는 파라미터
    if(version == 0){ //즉 정상 그래프를 탐색한다면
        visit[x] = 1; //이번 노드를 방문 처리해주고
        
        for(auto v : arr[x]){ //이번 노드에서 갈수 있는 모든 노드를 순서대로 접근한다. 여기서 input에서 문제의 기분으로 정렬했기 때문에 0부터 접근해도 무방
            if(visit[v] == 1) continue; //v가 방문을 했다면 continue로 아래 연산을 무시해준다.
            dfs(v,version,0); //v가 방문하지않았다면 dfs를 같은 버전으로 재귀로 호출
        }
        s.push(x); //x에서 dfs로 갈수 있던 모든 노드를 거치고 이번 노드를 스택에 푸쉬
        cout<<x<<" "; //문제의 조건중 첫번째 줄에는 stack에 push되는 순서대로 출력하는 조건 때문에 추가한 출력문
    }
    else { //version == 1이면 즉 역방향그래프를 탐색한다면
        visit[x] = leader; //해당 x에 leader를 visit에 저장, dfs의 시작이 leader가 된다. 어느 것도 연결되어있지 않다면 자기자신만이 리더인채로
                //함수는끝나게 된다.
        for(auto v : reverse_arr[x]){ //역방향 그래프로 갈수 있는 모든 것에 접근하다. 여기선 SCC의 원리에 따라 cmp기준을 따르지 않아도 된다.
            if(visit[v] != 0) continue;// 방문했다면 즉 leader가 표시되어있다면 건너뛰어준다.
            dfs(v,version,leader); //위에 조건이 아닐시, 다음 유저로 dfs 여기서 leader는 똑같이 유지해줘서 dfs시작 유저를 넘겨준다.
        }
    }
}
//알고리즘 단계 1
void print_first_ans(){ //첫번째 줄을 출력해주는 함수 즉 정상그래프를 스택에 넣는 역할을 한다.
    for(int i = 1; i<=n; i++){//모든 인덱스에 접근한다. 그래프가 연결되어있지 않을 수도 있기 때문에 모든 인덱스에 방문여부를 확인해야한다.
        if(!visit[vertexRank[i]]) dfs(vertexRank[i],0,0); //vertexRank에는 실행순위대로 저장되어있기때문에 실행순위대로 접근하되 해당
                                                          //vertex가 이미 방문했다면 건너뛰어준다.
    }
}
//알고리즘 단계 2
void print_second_ans(){ //두번째 줄을 출력해주는 함수 즉 SCC별로 leader를 출력해준다.
    cout<<endl; // 출력예시와 같이 첫째줄과 두번째줄을 개행해주는 라인
    for(int i=1;i<=n;i++) visit[i] = 0; //위에서 visit이 모두 1로 바뀌어있어서 다시 leader가 없다는 0을 넣어줘서 초기화
    while(!s.empty()){ // 스택이 빌때까지 모든 vertex의 SCC여부를 저장한다.
        int v = s.top();//스택의 top을 v에 선언 및 초기화
        s.pop(); //스택의 top을 빼준다.
        if(visit[v] != 0) continue;
        //만약 이번 v에 visit 즉 리더가 있을 경우 이미 dfs를 통해 SCC가 만들어진 상태이므로 건너뛴다.
        dfs(v,1,v); //방문을 한 적이 없으면 해당 v가 첫번쨰 dfs의 시작 vertex 즉 리더이므로 v를 leader로 version은 1로 dfs를 한다.
    }
    for(int i= 1; i<=n;i++){ //모든 vertex의 leader를 출력한다.
        //cout<<visit[i]<<" "; //해당노드의 leader를 출력한다. visit은 이미 leader를 저장하는 배열로 사용된 상태
    }
}

int main(){
    input();//변수 입력 및 정렬을한다.
    print_first_ans();//첫번째 줄을 출력한다
    print_second_ans();//두번째 줄을 출력하고 main을 종료한다.
}

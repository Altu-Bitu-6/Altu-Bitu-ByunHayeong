#include <iostream>  //표준입력 및 출력을 위한 헤더 파일
#include <vector>  //벡터 자료구조를 사용하기 위한 헤더 파일
#include <string>  //string을 사용하기 위한 헤더 파일
using namespace std;  //표준 라이브러리 사용할 때 std:를 생략할 수 있도록

vector<string> li;  //톱니바퀴 상태를 저장
vector<pair<int, int> > stack;  //회전할 톱니바퀴의 인덱스와 방향을 저장
vector<int> visited;  //방문 여부를 저장

void check_rotation(int current_num, int current_dir) {  //특정 톱니바퀴를 중심으로 인접한 톱니바퀴들을 회전할 수 있는지 확인하는 함수
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0) {  //왼쪽에 인접한 톱니바퀴가 존재하고 해당 톱니바퀴에 방문되지 않았을 때
        if (li[current_num][6] != li[current_num - 1][2]) { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num - 1, current_dir * -1));  //현재 톱니바퀴의 인덱스와 회전방향 stack에 삽입
            visited[current_num - 1] = 1;  //톱니바퀴에 방문했음을 표시
            check_rotation(current_num - 1, current_dir * -1);  //현재 톱니바퀴와 인접한 톱니바퀴들을 회전 가능한지 함수를 재귀호출하여 확인
        }
    }
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0) {  //오른쪽에 인접한 톱니바퀴가 존재하고 아직 방문하지 않았을 때
        if (li[current_num][2] != li[current_num + 1][6]) { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num + 1, current_dir * -1));  //현재 톱니바퀴의 인덱스와 회전방향 stack에 삽입
            visited[current_num + 1] = 1;  //톱니바퀴에 방문했음을 표시
            check_rotation(current_num + 1, current_dir * -1);  //현재 톱니바퀴와 인접한 톱니바퀴들을 회전 가능한지 함수를 재귀호출하여 확인
        }
    }
}

int main() {
    int t;  //톱니바퀴의 개수
    int k;  //회전 횟수

    cin >> t; //톱니바퀴의 개수 T 입력

    li.resize(t); //톱니바퀴 개수만큼 resize
    for (int i = 0; i < t; ++i)  //톱니바퀴 개수만큼 반복
        cin >> li[i]; //톱니바퀴 상태 입력

    cin >> k; // 회전 횟수 K 입력
    for (int i = 0; i < k; ++i) { //k번 돌면서 회전할 수 있는지에 대해 체크
        int num, direction;  //인덱스,방향 
        cin >> num >> direction; //방향 입력 (1이면 시계 방항, -1이면 반시계 방향)
        stack.clear();  //stack 초기화
        stack.push_back(make_pair(num - 1, direction));  //인덱스와 방향 삽입
        visited.assign(t, 0); //t개만큼 0을 초기화
        visited[num - 1] = 1;  //방문한 톱니바퀴 표시
        check_rotation(num - 1, direction); //인접 톱니바퀴들이 회전할 수 있는지 확인하는 함수 호출

        while (!stack.empty()) {  //stack이 비어있지 않다면
            pair<int, int> top = stack.back();  //stack의 맨 위 요소 가져오기
            stack.pop_back();  //stack의 맨 위 요소 제거
            int tmp_num = top.first; //돌려야 할 톱니바퀴의 인덱스
            int tmp_dir = top.second; //돌릴 방향
            if (tmp_dir == 1) { //시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);  //톱니바퀴 돌리기
            } else { //반시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];  //톱니바퀴 돌리기
            }
        }
    }

    int cnt = 0;  //상단 극이 1인 톱니바퀴의 개수
    for (int i = 0; i < t; ++i) {  //전체 톱니바퀴 개수만큼 반복
        if (li[i][0] == '1') {  //상단 극이 1이면
            cnt++; //cnt 증가
        }
    }

    cout << cnt << endl;  //cnt 출력

    return 0;  //main함수 종료
}
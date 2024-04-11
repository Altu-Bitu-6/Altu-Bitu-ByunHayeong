// 2615번 오목: https://www.acmicpc.net/problem/2615
#include <iostream>   //표준입력 및 출력을 위한 헤더 파일
#include <vector>  //벡터 자료구조를 사용하기 위한 헤더 파일

using namespace std;  //표준 라이브러리 사용할 때 std:를 생략할 수 있도록

typedef vector<vector<int>> matrix;  //바둑판
const int SIZE = 20, EMPTY = 0;  //SIZE와 EMPTY 상수 선언

// 방향에 따른 좌표 증가량
// 맨 왼쪽 위 돌을 기준으로 검사하기 때문에 오른쪽+아래쪽으로 향하는 방향만 정의
const vector<int> dx = {-1, 0, 1, 1};  //오른쪽+아래쪽으로 향하는 방향에 따른 X좌표 증가량
const vector<int> dy = {1, 1, 1, 0};  //오른쪽+아래쪽으로 향하는 방향에 따른 Y좌표 증가량

/**
 * 범위와 돌의 종류가 유효한지 확인한다.
*/
bool isValid(matrix &board, int x, int y, int color) {  //범위와 돌의 종류가 유효한지 확인하는 함수
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color);  //범위가 바둑판 안에 있는지와 돌의 종류 확인
}

/**
 * 해당 좌표(x, y)부터 연속적으로 5알이 놓이는지 확인한다.
*/
bool checkWin(matrix &board, int x, int y) {  //연속적으로 5알이 놓이는지 확인하는 함수
    int color = board[x][y]; // 기준 색

    // 4 방향에 대해 검사
    for (int idx = 0; idx < 4; idx++) {  //오른쪽+아래쪽으로 향하는 4방향에 대해 검사
        int cnt = 1;    // cnt: 같은 방향에 놓인 같은 색 돌의 수
        int prev_x = x - dx[idx], prev_y = y - dy[idx];   //이전의 x와 이전의 y 초기화
        int next_x = x + dx[idx], next_y = y + dy[idx];  //다음의 x와 다음의 y 초기화

        // 같은 방향에서 그 이전에도 같은 색 돌이 있었다면 패스 (-> 여섯 알 이상 놓이는 경우를 제외하기 위함)
        if (isValid(board, prev_x, prev_y, color)) {  //이전 상황에서도 연속적으로 5알이 놓였다면
            continue;  //패스
        }

        // 연속적으로 놓인 5알이 같은 색인지 확인
        while (isValid(board, next_x, next_y, color) && cnt < 6) {  //해당 x,y가 버위에 있고 돌의 종류가 유효하고 연속적으로 놓인 갯수가 6미만이면 반복
            next_x += dx[idx];  //다음 x
            next_y += dy[idx];  //다음 y
            cnt++;  //연속적으로 놓인 바둑알 갯수
        }
        // cnt가 5일 때만 true 리턴 (-> 다섯 알보다 적거나 다섯 알보다 많이 놓이는 경우를 제외)
        if (cnt == 5) {  //cnt가 5라면
            return true;  //true 리턴
        }
    }
    return false;  //연속적으로 5알 놓이지 않는 경우 false 리턴
}

int main() {
    // 입력
    matrix board(SIZE, vector<int>(SIZE, 0)); // 바둑판
    for (int i = 1; i < SIZE; i++) //19번 반복
        for (int j = 1; j < SIZE; j++)  //19번 반복
            cin >> board[i][j];  //바둑알 위치 입력받기

    // 연산 및 출력
    for (int y = 1; y < SIZE; y++) {  //19번 반복
        for (int x = 1; x < SIZE; x++) {  //19번 반복
            // 빈 칸이면 패스
            if (board[x][y] == EMPTY) {  //빈칸이면 
                continue;  //패스
            }
            // 해당 좌표(x, y)부터 연속적으로 5알이 놓였다면 정답 출력
            if (checkWin(board, x, y)) {  //연속적으로 5알이 놓였다면
                cout << board[x][y] << '\n'  //검은색이 이겼다면 1, 흰색이 이겼다면 2 출력
                     << x << ' ' << y;  //가장왼쪽의 가로줄 번호, 세로줄 번호 출력
                return 0;  //함수 종료
            }
        }
    }
    cout << 0;  //승부가 결정되지 않았을 경우 0출력

    return 0;  //함수 종
}
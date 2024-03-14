/**
 * https://www.acmicpc.net/problem/1063
*/
#include <iostream> // 표준 입력 및 출력을 위한 헤더 파일
#include <string> // 문자열 관련 기능을 사용하기 위한 헤더 파일
#include <vector> // 벡터 자료구조를 사용하기 위한 헤더 파일

using namespace std; // 표준 라이브러리를 사용할 때 std:를 생략할 수 있도록 함
typedef pair<char, char> cc; // char형 두 개의 값을 가지는 쌍 자료형을 cc로 정의

/**
 * input에 따라 이동한다.
*/
cc move(string input, char x, char y) {  //input : 이동방향, x : 현재 x좌표, y : 현재 y좌표
    for (char how : input) { // 문자열을 순회하면서
        if (how == 'R') { // 만약 'R'이라면
            x++; // 오른쪽으로 한 칸 이동
        } else if (how == 'L') { // 만약 'L'이라면
            x--; // 왼쪽으로 한 칸 이동
        } else if (how == 'B') { // 만약 'B'라면
            y--; // 아래쪽으로 한 칸 이동
        } else { // 그 외의 경우 ('T'라면)
            y++; // 위쪽으로 한 칸 이동
        }
    }
    return {x, y}; // 이동 후의 좌표를 반환
}

/**
 * 두 좌표의 위치가 일치하는지 확인한다.
*/
bool isSame(cc k, cc s) { //k : 첫번째 좌표, s : 두번째좌표
    return (k.first == s.first && k.second == s.second); // 두 좌표가 일치하는지 여부를 반환
}

/**
 * 체스판 범위를 넘어서는지 확인한다.
*/
bool checkRange (cc pos) { //pos : 확인할 좌표
    if (pos.first < 'A' || pos.first > 'H' || pos.second < '1' || pos.second > '8') { // 만약 x 또는 y 좌표가 체스판을 벗어난다면
        return false; // false 반환
    }
    return true; // 그렇지 않다면 true 반환
}

int main() {  //main 함수
    cc k, s;  // king, stone의 위치를 나타내는 좌표 변수
    int n; // 이동 횟수를 나타내는 변수
    string input; // 이동 방향을 담을 문자열 변수

    // 입력
    cin >> k.first >> k.second >> s.first >> s.second >> n; // king과 stone의 초기 위치, 이동 횟수를 입력받음

    // 연산
    while (n--) { // 이동 횟수만큼 반복
        cin >> input; // 이동 방향을 입력받음

        cc next_k, next_s; // 다음 king과 stone의 위치를 저장할 변수 선언

        // king 이동
        next_k = move(input, k.first, k.second); // move 함수를 호출하여 king을 이동시킴

        // stone 이동
        if (isSame(next_k, s)) { // 만약 king과 stone의 이동 후 위치가 일치한다면
            // king이 움직인 방향과 같은 방향으로 stone도 이동
            next_s = move(input, s.first, s.second); // move 함수를 호출하여 stone을 이동시킴
        }
        else {
            next_s = s; // 이동하지 않음
        }

        // 체스판 밖으로 나가지 않을 경우만 이동
        if (checkRange(next_k) && checkRange(next_s)) { // 다음 위치가 체스판 안에 있으면
            k = next_k; // king의 위치를 업데이트
            s = next_s; // stone의 위치를 업데이트
        }
    }

    // 출력
    cout << k.first << k.second << '\n' << s.first << s.second; // king과 stone의 최종 위치 출력

    return 0; // 프로그램 종료
}
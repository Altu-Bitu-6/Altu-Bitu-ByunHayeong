// 16401: 과자 나눠주기 (실버2/이분 탐색, 매개 변수 탐색)
#include <iostream>  //표준입력 및 출력을 위한 헤더 파일
#include <vector>  //벡터 자료구조를 사용하기 위한 헤더 파일

using namespace std;  //표준 라이브러리 사용할 때 std:를 생략할 수 있도록

/*
* 이분 탐색을 이용하여 나눠줄 수 있는 최대한 긴 과자의 길이를 찾아낸다.
*/

#define MAX_COOKIE 1000000000  //과자의 최대 길이 상수 선언

int binarySearch(int m, vector<int> &cookie) {  //이분탐색하는 함수
    int right = MAX_COOKIE; // 과자의 최대 길이: 1000000000
    int left = 1; // 과자의 최소 길이: 1
    int res=0;  //조카 1명에게 줄 수 있는 막대 과자의 최대 길이

    while (left <= right) {  //left가 right보다 커지면 반복 종료
        int mid = (left + right) / 2;  //mid 초기화
        int cnt = 0;  //일정길이 mid로 잘랐을 대 나오는 총 조각의 수
        // mid 길이만큼씩 나눠주면 몇 명에게 나눠줄 수 있는지 세기
        for (int i = 0; i < cookie.size(); i++) {  //과제 갯수만큼 반복
            cnt += cookie[i] / mid;  //과자의 길이 일정 길이 mid로 자르기
        }
        if (cnt >= m) {  //이 조각의 수가 조카 수보다 크거나 같으면 
            left = mid + 1;  //더 긴 깅이로 줄 수 있는지 확인하기 위해 left옮기기
            res = mid;  //조카에게 나누어줄 수 있으므로 길이 mid 기록
        }
        else{  //아니라면
            right = mid - 1;  //mid값 줄이기 위해 right옮기기
        }
    }
    return res; //결과 리턴
}

int main() {
    int m, n;  // 조카 수, 과자 수 입력받을 변수
    cin >> m >> n;  //조카 수, 과자 수 입력
    vector<int> cookie(n);  //과자의 길이 입력받을 벡터
    
    // 막대과자 길이 입력
    for (int i = 0; i < n; i++) {  //과자 수만큼 반복
        cin >> cookie[i];  //과자의 길이 입력
    }

    
    cout << binarySearch(m, cookie);  // 연산 & 출력

    return 0;  //main함수 종료
}
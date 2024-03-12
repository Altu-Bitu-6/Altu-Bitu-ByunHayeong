#include <iostream>  //입출력 클래스가 정의되어 있는 헤더 파일의 내용을 소스파일에 포함시킴
#include <vector>  //벡터 헤더 파일의 내용을 소스 파일에 포함시킴

using namespace std;  //std::를 호출하는 번거로움 줄임

typedef pair<int, char> ic;  //int와 char로 이루어진 쌍을 나타내는 자료형
const int ALPHA = 26;  //알파벳 개수

//index부터 시계방향으로 바퀴에 적어놓은 알파벳 출력
string printWheel(int n, int index, vector<char>& wheel) {  //index부터 시계방향으로 바퀴에 적은 알파벳 출력하는 함수
	string ans = "";  //출력할 문자열 초기화
	//바퀴를 돌릴 때와 반대방향으로 출력
	for (int i = index + n; i > index; i--) {  //index부터 시작해 시계반대방향으로 돌며
		ans += wheel[i % n];  //알파벳을 문자열에 추가
	}
	return ans;  //문자열 반환
}

//행운의 바퀴 반환
string makeWheel(int n, int k, vector<ic>& record) {  //행운의 바퀴 만드는 함수
	vector<char> wheel(n, '?'); //바퀴의 모든 알파벳을 ?로 초기화
	vector<bool> is_available(ALPHA, false); // 알파벳 중복 체크

	int index = 0; //화살표가 가리키는 인덱스

	for (int i = 0; i < k; i++) {  //연산 횟수만큼 반복
		int s = record[i].first; //화살표가 가리키는 글자가 변하는 횟수
		char ch = record[i].second; //회전을 멈추었을 때 가리키던 글자

		index = (index + s) % n; //회전한 후 화살표가 가리키는 인덱스

		//해당 칸이 ch로 이미 채워져 있는 경우 넘어감
		if (wheel[index] == ch) {  //해당 칸이 ch로 이미 채워져 있는 경우
			continue;  //넘어감
		}

		//다른 글자로 채워져있거나 해당 글자가 이미 사용된 알파벳인 경우 ! 반환
		if (wheel[index] != '?' || is_available[ch - 'A']) {  //다른 글자로 채워져 있거나 이미 사용된 알파벳인 경우
			return "!";  //!반환
		}

		wheel[index] = ch; //해당 칸에 글자 적기
		is_available[ch - 'A'] = true; //해당 알파벳이 사용되었으므로 true로 변경
	}
	return printWheel(n, index, wheel);  //현재 인덱스부터 바퀴에 적인 알파벳 반환
}

int main() {
	ios::sync_with_stdio(false);  //입출력 성능 향상
	cin.tie(NULL); cout.tie(NULL);  //입출력 스트림을 묶어서 성능 향상

	//입력
	int n, k;  //바퀴의 크기와 연산 횟수를 나타내는 변수 선언
	cin >> n >> k;  //바퀴의 크기와 연산 횟수 입력 받음

	vector<ic> record(k);  //연산을 나타내는 정수와 문자의 쌍을 나타내는 벡터 선언
	for (int i = 0; i < k; i++) {  //연산 횟수만큼 반복
		cin >> record[i].first >> record[i].second;  //연산을 나타내는 정수의 문자의 쌍 입력 받음
	}

	//연산 & 출력
	cout << makeWheel(n, k, record);  //makeWheel 함수 호출하여 바퀴 생성하고 결과 출력

	return 0;  //프로그램 종료
}
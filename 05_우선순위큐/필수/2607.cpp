// 2607: 비슷한 단어 (실버3/구현, 문자열)
#include <iostream> //표준 입력 및 출력을 위한 헤더 파일
#include <vector>  //벡터 자료구조를 사용하기 위한 헤더 파일

using namespace std;  //표준 라이브러리를 사용할 때 std:를 생략할 수 있도록 함
const int NUM_CHARS = 26;  //알파벳의 개수

/*
* 원본 단어와의 차이의 개수를 센다.
*/

/*
 * [비슷한 단어]
 *
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */

// 각 알파벳의 개수 세기
void countFreq(string word, vector<int> &freq) {  //각 알파벳의 개수를 세는 함수
    for (int i = 0; i < word.length(); i++) {  //단어의 길이만큼 반복
        freq[word[i] - 'A']++; //문자를 숫자로 변환하여 알파벳 빈도수 증가시키기
    }
}

int countDiff(string word, vector<int> original_freq) {
    vector<int> freq(NUM_CHARS, 0);  //각 알파벳의 빈도수를 저장할 벡터 초기화
    int diff = 0; // 원본 단어와의 차이 

    countFreq(word, freq); // 각 알파벳의 빈도수 세기
    
    // 원본 단어와 다른 알파벳 개수 구하기
    for (int i = 0; i < NUM_CHARS; i++) {  //알파벳 개수만큼 반복
        diff += abs(original_freq[i] - freq[i]);  //각 알파벳 빈도수 차이의 절댓값 누적시키기
    }
    return diff;  //원본 단어와의 차이 리턴
}

int main() {
    int N, ans=0;  //단어의 개수, 답
    string original;  //첫번째 단어
    // 입력
    cin >> N;  //단어의 개수 입력받기
    cin >> original;  //첫번째 단어 입력받기
    vector<int> original_freq(NUM_CHARS, 0);  //단어의 알파벳 빈도수를 저장할 벡터 초기화

    // 연산
    countFreq(original, original_freq);  //알파벳 개수 세는 함수 호출

    for (int i = 1; i < N; i++) {  //단어의 개수만큼 반복
        string word;  //비교할 단어 선언
        cin >> word;  //비교할 단어 입력받기

        int diff = countDiff(word, original_freq); //첫번째 단어와 다른 알파벳 개수 구하는 함수 호출
        // 비슷한 단어 세기
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()) {  //같은 구성인 경우, 단어와 원본 단어의 차이가 하나인 경우(더하거나 뺀 경우), 단어와 원본 단어의 차이가 두 개이고 단어의 길이가 동일한 경우(변경한 경우)
            ans++;  //비슷한 단어 개수 증가시키기
        }
    }
    // 출력
    cout << ans;  //비슷한 단어 개수 출력하기
    return 0;  //프로그램 종료
}
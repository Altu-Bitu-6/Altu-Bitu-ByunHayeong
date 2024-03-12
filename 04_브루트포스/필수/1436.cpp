#include <iostream>
#include <string>

using namespace std;

int n_movie(int num)
{
    int cnt;
    int result = 665;
    string s;
    
    while(result++)
    {
        s = to_string(result); //string으로 바꾸기
        if(s.find("666")!=-1) //"666"이 있는지 찾기
        {
            cnt++; //있으면 cnt증가
        }
        if(cnt==num) //cnt가 num이랑 같으면 result 리턴
        {
            return result;
        }
    }
    return 0;
}

int main()
{
    int num, result; //n번째 영화, 결과
    cin >> num; 
    
    result = n_movie(num);
    cout << result;
    return 0;
}
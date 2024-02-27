#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string a, string b)
{
    string result;

    //자릿수 맞추기
    int len = max(a.length(), b.length());  
    a = string(len - a.length(), '0') + a;
    b = string(len - b.length(), '0') + b;

    int next = 0;; //다음으로 올릴 수
    for(int i = len-1; i>=0; i--)
    {
        int sum = (a[i]-'0')+(b[i]-'0')+next;
        next = sum/10;
        result += sum%10+'0';
    }

    if(next>0)
    {
        result += next+'0';
    }
    reverse(result.begin(), result.end());
    
    return result;
}

int main()
{
    string a, b;
    cin>>a>>b;
    string result = add(a,b);
    cout<<result;
    return 0;
}
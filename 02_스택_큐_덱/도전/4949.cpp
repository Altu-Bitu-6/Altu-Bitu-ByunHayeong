#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBalanced(string input)
{
    stack<char> s;

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i]=='('||input[i]=='[')
        {
            s.push(input[i]);
        }else if(input[i]==')')
        {
            if(s.empty()||s.top()!='(') //괄호의 짝이 맞지 않는 경우
            {
                return false;
            }else
            {
                s.pop();
            }
        }else if(input[i]==']')
        {
            if(s.empty()||s.top()!='[')  //괄호의 짝이 맞지 않는 경우
            {
                return false;
            }else
            {
                s.pop();
            }
        }
    }

    if(s.empty())
    {
        return true; //괄호의 짝이 맞는 경우
    }

    return false; //괄호의 짝이 맞지 않는 경우
}

int main()
{
    while(true)
    {
        string input;
        getline(cin, input);

        if(input==".")
        {
            break;
        }
        if(isBalanced(input))
        {
            cout<<"yes"<<"\n";
        }else
        {
            cout<<"no"<<"\n";
        }
    }
    
    return 0;

}
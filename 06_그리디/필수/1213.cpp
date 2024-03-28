#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string check(string name)
{
    int alphabet[26] = {0};
    int cnt = 0; //알파벳이 홀수개인 경우의 갯수
    int middle = -1; //알파벳이 홀수개인 경우
    string s1;
    string s2;
    
    for(int i=0; i<name.length(); i++)
    {
        alphabet[name[i]-'A']++;
    }
    
    for(int i=0; i<26; i++)
    {   if(alphabet[i]>0){
            if(alphabet[i]%2!=0)
            {
                cnt++;
                middle = i;
            }
        }
    }
    
    if(cnt>1)
    {
     return "I'm Sorry Hansoo";   
    }else
    {
        for(int i=0; i<26; i++)
        {
            if(alphabet[i]>0)
            {
                for(int j=0; j<alphabet[i]/2; j++)
                {
                    s1+=(i+'A');
                }
                
            }
        }
        
        s2 = s1;
        reverse(s1.begin(),s1.end());
        if(middle!=-1)
        {
            s2 += (middle+'A');
        }
        return s2+s1;
    }
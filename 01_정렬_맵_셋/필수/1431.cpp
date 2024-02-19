#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(const string& s1, const string& s2)
{
    if(s1.length()<s2.length())
    {
        return true;
    }else if(s1.length()>s2.length())
    {
        return false;
    }else
    {
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<s1.length(); i++)
        {
            if(isdigit(s1[i]))
            {
                sum1+=s1[i]-'0';
            }
            if(isdigit(s2[i]))
            {
                sum2+=s2[i]-'0';
            }
        }
        if(sum1<sum2)
        {
            return true;
        }else if(sum1>sum2)
        {
            return false;
        }else
        {
            for(int i=0; i<s1.length(); i++)
            {
                if(s1[i]>s2[i])
                {
                    return false;
                }else if(s1[i]<s2[i])
                {
                    return true;
                }
            }
            return true;
        }
    }
}

int main()
{
    int n;
    vector<string> numbers;
    cin>>n;
    numbers.assign(n,"");
    for(int i=0; i<n; i++)
    {
        cin>>numbers[i];
    }

    sort(numbers.begin(), numbers.end(), cmp);
    for(int i=0; i<numbers.size(); i++)
    {
        cout<<numbers[i]<<'\n';
    }
    return 0;
}
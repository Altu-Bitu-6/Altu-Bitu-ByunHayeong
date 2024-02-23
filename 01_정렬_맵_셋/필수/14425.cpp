#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    set<string> s;
    int result = 0;

    cin>>n>>m;
    for(int i=0; i<n;i++)
    {
        string str;
        cin>>str;
        s.insert(str);
    }

    for(int i=0; i<m; i++)
    {
        string str;
        cin>>str;
        if(s.find(str)!=s.end())
        {
            result++;
        }
    }
    cout<<result;

    return 0;
}
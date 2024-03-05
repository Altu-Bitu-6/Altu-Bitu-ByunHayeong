#include <iostream>
#include <queue>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin>>n>>k;

    queue<int> q;
    for(int i=1; i<=n; i++) //1~n까지 담은 큐
    {
        q.push(i);
    }


    //출력
    cout<<"<";
    while(!q.empty())
    {
        for(int i=0; i<k-1; i++)
        {
            q.push(q.front()); 
            q.pop();
        }

        cout<<q.front(); //k번째 요소 출력
        q.pop(); //k번째 요소 삭제

        if(!q.empty()) //큐가 비어있지 않다면
        {
            cout<<", ";
        }
    }
    cout<<">";
}
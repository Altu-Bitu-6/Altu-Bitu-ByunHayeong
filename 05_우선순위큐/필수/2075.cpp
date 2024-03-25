#include <iostream>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; //n*n의 표
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq; //최소힙

    int x; //수
    for(int i=0; i<n*n; i++)
    {
        cin >> x;
        pq.push(x);
        if(pq.size()>n) pq.pop();  //n개가 넘지 않도록
    }
    cout << pq.top(); //n개 중 최소값 출력
}
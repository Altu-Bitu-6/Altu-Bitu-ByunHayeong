#include <iostream>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    priority_queue<int> max_heap;
    int n, a; // 아이들과 거점지를 방문한 횟수, a개의 선물
    int p; // 충전한 선물
    cin >> n;

    while(n--)
    {
        cin >> a;
        if(a==0) 
        {
            if(!max_heap.empty()) //선물이 없을 때
            {
                int present = max_heap.top();  //가치가 큰 선물 리턴
                cout << present <<"\n";   //선물 가치 출력
                max_heap.pop();  //해당 선물 삭제

            }else  //선물이 있을 때
            {
                cout << -1 << "\n";
            }

        }else if(a>0)
        {
            while(a--) // 충전한 선물 갯수만큼 반복
            {
                cin >> p;
                max_heap.push(p);  //선물 추가
            }
        }
        
    }

}
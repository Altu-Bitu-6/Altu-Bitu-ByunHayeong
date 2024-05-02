#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> visited;
queue<int> q;

int bfs(vector<vector<int>>& li, int n, int a, int b)
{
    q.push(a);
    while(!q.empty())
    {
        int tmp = q.front();
        if(tmp==b)
        {
            return visited[tmp];
        }
        for(int i=0; i<li[tmp].size(); i++)
        {
            int nxt = li[tmp][i];
            if(visited[nxt]==0)
            {
                q.push(nxt);
                visited[nxt] = visited[tmp]+1;
            }
        }
        q.pop();
    }
    return -1;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int n; //전체 사람의 수
    int a, b; //촌수를 계산해야 하는 서로 다른 두 사람의 번호
    int m; // 부모 자식 관계의 개수 == 간선의 개수
    cin >> n >> a >> b >> m;
    
    vector<vector<int>> li(n+1);
    visited.assign(n+1,0);
    
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;
        li[x].push_back(y);
        li[y].push_back(x);
    }

    cout << bfs(li, n, a, b);
    
    
    return 0;
}
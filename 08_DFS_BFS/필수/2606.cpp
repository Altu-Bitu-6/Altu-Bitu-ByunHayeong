#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//VFS 사용

vector<vector<int>> li;
vector<bool> visited;

int bfs(int n)
{
    int result = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty())
    {
        int current_v = q.front();
        q.pop();
        for(int i=1; i<=n; i++)
        {
            if(li[current_v][i]==1&&!visited[i])
            {
                visited[i] = true;
                q.push(i);
                result++;
            }
        }
        
    }
    
    return result;
}

int main()
{
    int n; //컴퓨터 수
    int k; //간선의 수
    cin >> n >> k; 
    li.assign(n+1, vector<int>(n+1,0));
    visited.assign(n+1, false);
    
    for(int i=0; i<k; i++)
    {
        int a, b;
        cin >> a >> b;
        li[a][b] = li[b][a] = 1;
    }
    
    vector<int> ans_bfs;
    cout << bfs(n);
    
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
int subtree[100001];
bool visited[100001];

void query(int r) {
    visited[r] = true;
    subtree[r] = 1;  
    for (int i = 0; i < tree[r].size(); i++) {
        int next = tree[r][i];
        if (!visited[next]) {
            query(next);
            subtree[r] += subtree[next]; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, r, q, a, b;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    visited[r] = true;
    query(r);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << subtree[x] << '\n';
    }
    return 0;
}

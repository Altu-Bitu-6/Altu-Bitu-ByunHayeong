#include <iostream>
#include <vector>

using namespace std;

int visited[100002];

int solution(int n, int k, vector<int> &v){
    int result = 0;
    int st = 0;
    int en = 0;
    for(int st=0; st<n; st++){
        while(en<n&&visited[v[en]]<k){
            visited[v[en]]++;
            en++;
        }
        result = max(result, en-st);
        if(en==n)break;
        visited[v[st]]--;
    }
    return result;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n,0);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    cout << solution(n, k, v);

    return 0;
}
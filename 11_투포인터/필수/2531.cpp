#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int check[30001];

int calMax(int n, int k, int c, vector<int> &v){
    int result = 0;
    int cnt=0;
    int left = 0; int right = k-1;
    for(int i=0; i<k; i++){
        check[v[i]]++;
        if(check[v[i]]==1){
            cnt++;
        }
    }
    check[c]++;
    if(check[c]==1) cnt++;
    
    while(left<n){
        result = max(result, cnt);
        if(--check[v[left++]]==0){
            cnt--;
        }
        right = (right+1)%n;
        if(++check[v[right]]==1){
            cnt++;
        }
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,d,k,c; //벨트에 놓인 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시수, 쿠폰 번호
    
    cin >> n >> d >> k >> c;
    vector<int> v(n,0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    cout << calMax(n, k, c, v);
    return 0;
}
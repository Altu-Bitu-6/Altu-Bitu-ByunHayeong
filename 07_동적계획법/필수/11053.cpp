#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(1001,0);
vector<int> dp(1001,1);  //최소가 1 이므로 1로 초기화화

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    
    int result = dp[1];
    
    for(int i=1; i<=n; i++){
        result = max(result, dp[i]);
    }
    
    cout << result;
}
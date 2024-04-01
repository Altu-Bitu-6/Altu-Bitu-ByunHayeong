#include <iostream>

using namespace std;

int score[301];
int dp[301];

// dp[n] = dp[n-2] + score[n] or dp[n-3] + score[n-1] + score[n]
int main()
{
    int n;  //계단의 개수
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> score[i];
    }
    
    dp[1] = score[1];
    dp[2] = score[1]+score[2];
    dp[3] = max(score[1]+score[3], score[2]+score[3]);
    
    for(int i=4; i<=n; i++)
    {
        dp[i] = max(dp[i-2]+score[i], dp[i-3]+score[i-1]+score[i]);
    }
    
    cout << dp[n];
    
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 1000000

vector<bool> isPrimes(int n)
{
    vector<bool> primes(MAX+1, true);
    primes[0] = false;
    primes[1] = false;
    
    for(int i=2; i*i<=MAX; i++)
    {
        if(primes[i])
        {
            for(int j = i*i ; j<=n; j+=i)
            {
                primes[j] = false;
            }
        }
    }
    return primes;
}



int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, left, right;
    vector<bool> primes = isPrimes(MAX);
    while(1)
    {
        cin>>n;
        
        if(n==0)
        {
            return 0;
        }
        
        
        
        left = 3;
        right = n-3;
        
        
        
        while(left<=right)
        {
            if(primes[left]==true && primes[right]==true)
            {
                break;
            }
            left += 2;
            right -= 2;
        }
        
        if(left>right)
        {
            cout<<"Goldbach's conjecture is wrong."<<"\n";
        }else{
            cout<<n<<" = "<<left<<" + "<<right<<"\n";
        }
        
    }
    
    return 0;
}
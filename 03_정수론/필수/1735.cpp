#include <iostream>
#include <algorithm>

using namespace std;

int getGcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return getGcd(b, a%b);
}

int main()
{
    int a1, b1, a2, b2; //a1/b1, a2/b2
    cin>>a1>>b1>>a2>>b2;
    
    int gcd = getGcd(max(b1,b2), min(b1,b2)); //최대공약수
    int lcm = b1*b2/gcd; //최소공배수
    
    int num = a1*(lcm/b1) + a2*(lcm/b2);
    
    int gcd2 = getGcd(max(lcm, num), min(lcm, num));
    
    lcm /= gcd2;
    num /= gcd2;
    
    cout<<num<<" "<<lcm;
}
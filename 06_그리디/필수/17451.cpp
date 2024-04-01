#include <iostream>
#include <vector>

using namespace std;

long find_result(int n, vector<int> &v)
{
    long tmp = 0;

    for(int i = n-1; i>=0; i--)
     {
         if(v[i]>=tmp)
         {
             tmp = v[i];
         }
         else if(v[i]<tmp)
         {    
             long div = (tmp/v[i]);
             if(tmp%v[i]!=0)
             {
                 div++;
             }
             tmp = v[i] * div;
         }
     }

     return tmp;

}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int n; 
    vector<int> v;
    
    cin >> n;
    v.assign(n,0);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    
    cout << find_result(n, v);

}
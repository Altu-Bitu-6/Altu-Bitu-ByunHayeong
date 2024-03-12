#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int S = 0; //집합 S
    
    int n; //수행해야하는 연산의 수
    cin>>n;
    
    int i = 0;
    string s; //연산종류
    int x; //연산해야하는 수
    while(i!=n)
    {
        cin>>s;
         if(s == "add"){
                cin>>x;
                S |= (1<<x);
         }else if(s == "remove"){
                cin>>x;
                S &= ~(1<<x);
         }else if(s == "check"){
                cin>>x;
                if(S & (1<<x)){   //있으면
                    cout << "1"<<"\n";
                } else{
                    cout << "0"<<"\n";
                }
         }else if(s == "toggle"){
                cin>>x;
                if(S & (1<<x)){  //있으면
                    S &= ~(1<<x); //제거
                } else{             //없으면
                    S |= (1<<x);     //추가
                }
         }else if(s == "all"){
                S = (1<<21) - 1;
         }else if(s == "empty"){
                S = 0;
         }
        
        i++;
    }
    return 0;
}

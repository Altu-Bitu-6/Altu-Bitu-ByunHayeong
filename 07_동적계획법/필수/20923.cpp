#include <iostream>
#include <deque>
#include <string>

using namespace std;

string game(int m, deque<int> dodo, deque<int> suyeon)
{
    bool turn = true; //true면 dodo차례, false면 suyeon차례
    int cnt = 0;
    string result = ""; //이긴 사람
    deque<int> dodo_ground;
    deque<int> suyeon_ground;
    
    while(true)
    {   
        cnt++;
        
        if(turn)
        {
            dodo_ground.push_back(dodo.back());
            dodo.pop_back();
            
            
        }else{
            suyeon_ground.push_back(suyeon.back());
            suyeon.pop_back();
        }
        
        if(dodo.size()==0)
        {
            result = "su";
            break;
        }else if(suyeon.size()==0)
        {
            result = "do";
            break;
        }
        
        
        if(dodo_ground.back()+suyeon_ground.back()==5&&dodo_ground.size()!=0&&suyeon_ground.size()!=0)
        {
            while(dodo_ground.size()>0)
            {
                suyeon.push_front(dodo_ground.front());
                dodo_ground.pop_front();
            }
            while(suyeon_ground.size()>0)
            {
                suyeon.push_front(suyeon_ground.front());
                suyeon_ground.pop_front();
            }
        }else if(dodo_ground.size() != 0 && dodo_ground.back() == 5 || suyeon_ground.size() != 0 && suyeon_ground.back() == 5)
        {
            while(suyeon_ground.size()>0)
            {
                dodo.push_front(suyeon_ground.front());
                suyeon_ground.pop_front();
            }
            while(dodo_ground.size()>0)
            {
                dodo.push_front(dodo_ground.front());
                dodo_ground.pop_front();
            }
        }
        
        if(cnt == m)
        {
            if(dodo.size()>suyeon.size())
            {
                result = "do";
            }else if(dodo.size()<suyeon.size())
            {
                result = "su";
            }else
            {
                result = "dosu";
            }
            break;
        }
        turn = !turn;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;  //가지는 카드의 개수, 게임 진행 횟수
    cin >> n >> m;
    deque<int> dodo(n);
    deque<int> suyeon(n);
    
    for(int i=0; i<n; i++)
    {
        cin >> dodo[i] >> suyeon[i];
    }
    
    cout << game(m, dodo, suyeon);

    return 0;
}
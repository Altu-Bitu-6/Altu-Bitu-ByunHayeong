#include <iostream>
#include <vector>

using namespace std;

void print(int start, int end, vector<int> &v){
    if(start>=end)return;
    if(start == end-1){
        cout << v[start] << '\n';
        return;
    }
    int index = start+1;
    while(index<end){
        if(v[start]<v[index]) break;
        index++;
    }
    print(start+1, index, v);
    print(index, end, v);
    cout << v[start] << '\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> v;
    int x;

    while(cin>>x){
        v.push_back(x);
    }

    print(0, v.size(), v);

    return 0;
}
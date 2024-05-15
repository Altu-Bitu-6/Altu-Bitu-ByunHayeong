#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> x;

bool isShine(int height, int n, int m){
    for(int i=0; i<m; i++){
        if(i==0){
            if(x[i]-height>0) return false;
        }
        if(x[i]-height > x[i-1] + height){
            return false;
        }
        if(i==m-1){
            if(x[i]+height<n){
                return false;
            }
        }
    }
    return true;
}

int cal_height(int n, int m, int right){
    int left = 1;
    int mid;
    int height = 0;
    while(left<=right){
        mid = (left+right)/2;
        if(isShine(mid, n, m)){
            right = mid-1;
            height = mid;
        }else{
            left = mid+1;
        }
    }
    return height;
}

int main(){
    
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    
    int n, m, right;
    cin >> n >> m;
    x.assign(m,0);
    right = n;
    for(int i=0; i<m; i++){
        cin >> x[i];
        right = max(x[i], right);
    }
    
    cout << cal_height(n,m, right);
    
    return 0;
}
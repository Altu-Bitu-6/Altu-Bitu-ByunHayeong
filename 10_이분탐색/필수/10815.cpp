#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, vector<int> &v1, int key){
    int left = 0;
    int right = n-1;
    int mid;
    
    while(left<=right){
        mid = (left+right)/2;
        if(v1[mid]==key){
            return 1;
        }else if(v1[mid]>key){
            right = mid-1;
        }else{
            left = mid +1;
        }
    }
    return 0;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    
    int n, m, key;
    cin >> n;
    vector<int> v1(n);
    for(int i=0; i<n; i++){
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());
    
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> key;
        cout << binarySearch(n, v1, key) << " ";
    }

    return 0;
}
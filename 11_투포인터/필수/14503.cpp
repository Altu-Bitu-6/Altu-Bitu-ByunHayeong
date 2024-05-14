#include <iostream>


using namespace std;

int r,c,d;  //청소기가 있는 칸의 좌표, 바라보는 방향

int cal_clean(){
    int cnt = 0;
    //현재 칸의 주변 중 청소되지 않은 곳이 없는 경우
    // 위 : r, c-1 / 아래 : r, c+1 / 왼 : r-1, c / 오 : r+1, c
    //현재 칸의 주변 중 청소되지 않은 곳이 있는 경우

    return cnt;
}

int main(){

    int n,m; //방의 크기
    cin >> n >> m;
    cin >> r >> c >> d;
    int room[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> room[i][j];
        }
    }

    cout << cal_clean();

    return 0;

}
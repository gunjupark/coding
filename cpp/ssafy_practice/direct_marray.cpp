#include <iostream>
using namespace std;

int map[5][6] = {
    1, 0, 2, 1, 2, 1,
    -1, 0, 1, 1, 2, 2,
    3, 3, 1, 2, 3, 4,
    5, 5, 5 ,3, 1, 2,
    1, 2, 3, 4, 0, 0
};

int sum[5][6];

int dx[] = {-1,-1,1,1,0};
int dy[] = {-1,1.-1,1,0};

int main()
{
    //세 좌표를 입력받고
    //다섯 곳의 합을 구하는데
    //세 곳중 MAX값 출력
    int lx,ly,rx,ry;
    int max_sum = -9999999;
    for (int i=0; i < 5; ++i){
        for(int j=0; j<6; ++j){

            // 아래 값 대신 dx,dy 만들어서 direct 접근이 효율적
            lx = j-1; ly = i-1;
            rx = j+1; ry = i+1;

            if(lx >=0 && rx <6 && ly >=0 && ry <5){
                sum[i][j] = map[ly][lx]+map[ly][rx]+map[ry][lx]+map[ry][rx]+map[i][j];
                if(sum[i][j] > max_sum) max_sum = sum[i][j];
            }
        }
    }

    cout << max_sum << "\n";

    return 0;
}
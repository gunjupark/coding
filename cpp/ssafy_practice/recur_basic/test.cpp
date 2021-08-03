#include <iostream>
#include <vector>

using namespace std;

int map[4][6] = {
    5,8,3,2,6,5,
    1,0,0,0,0,0,
    2,0,0,0,0,0,
    6,0,0,0,0,0,
};

int main(){
    for (int i=1; i<4;++i){
        for (int j=1; j<6; ++j){
            map[i][j] = min(map[i-1][j], map[i][j-1]) +3;
        }
    }
    printf("%d \n", map[3][5]);

    return 0 ;
}
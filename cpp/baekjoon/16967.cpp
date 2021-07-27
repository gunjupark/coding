#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int b[600][600];

int a[300][300];

int main() {
    int h,w,x,y;
    cin >> h >> w >> x >>y;

    for (int i=0; i< h+x; i++){
        for (int j=0; j< w+y; j++){
            cin >> b[i][j];
        }
    }

    // Divided 4 space
    //  1. 0 <= r < x   && 0 <= c < w : original A
    //  2. 0 <= c < y   && x <= r < h : original A
    //  3. x <= r < h   && y <= c < w : B (added)

    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if(i < x || (i >= x && j < y)){
                a[i][j] = b[i][j];
            }
            // 핵심 part (added b -> original a)
            if (i >= x && j >=y){
                a[i][j] = b[i][j] - a[i-x][j-y];
            }

            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
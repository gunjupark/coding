#include <iostream>
#include <vector>

using namespace std;

int cmap[5][5];

int call[25];

int main(){
    for (int i=0; i < 5; i++){
        for (int j=0; j<5; j++){
            cin >> cmap[i][j];
        }
    }

    for (int i=0; i <25; i++){
        cin >> call[i];
    }

    int cnt = 0;

    for (int i=0; i< 25 ; i++){
        bool find_flag = false;

        if(cnt >2) {
            cout << i << "\n";
            break;
        }
        for (int r =0; r <5; r++){
            for (int c=0; c<5; c++){
                if(call[i] == cmap[r][c]) {
                    find_flag = true;
                    cmap[r][c] = 0;
                    // 빙고 체크 변수 : psum
                    int psum=0;
                    // horizon bingo
                    for (int x=0; x<5; x++){
                        psum+= cmap[r][x];
                    }
                    if(psum==0) cnt++;
                    else psum =0;
                    // vertical bingo
                    for (int y=0; y<5; y++){
                        psum+= cmap[y][c];
                    }
                    if(psum==0) cnt++;
                    else psum =0;

                    // diagonal bingo /
                    if(r+c == 4) {
                        for (int d=0; d<5; d++) {
                            psum+= cmap[d][4-d];
                        }
                        if(psum==0) cnt++;
                        else psum =0;
                    }
                    // diagonal bingo \

                    if(r==c) {
                        for (int d=0; d<5; d++) {
                            psum+= cmap[d][d];
                        }
                        if(psum==0) cnt++;
                        else psum =0;
                    }

                }
            }
            if(find_flag) break;
        }
    }


    return 0;
}
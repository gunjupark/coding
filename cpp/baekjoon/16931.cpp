#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


int h[100][100];
/*
void print_h(int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%d ", h[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
*/

int main() {
    int n, m;
    cin >> n >> m;

    int answer =0;
    int max_h=0;
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> h[i][j];
            if(h[i][j]> max_h) max_h = h[i][j];
        }
    }

    // 윗면, 아랫면 겉넓이
    answer += 2*n*m;  

    int tmp,nx,ny;
    while(max_h > 0){
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                tmp = 0;
                if(h[i][j]==max_h && h[i][j] >0){
                    for (int k=0; k<4; k++){
                        nx = j + dx[k];
                        ny = i + dy[k];

                        if(nx >= m || ny >= n || nx < 0 || ny <0 ){
                            tmp++;
                        }
                        else{
                            if(h[i][j] != h[ny][nx]){
                                tmp++;
                            }
                        }
                    }
                }
                answer += tmp;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j < m; j++){
                if(h[i][j]==max_h) h[i][j]--;
            }
        }

        //printf("answer: %d, max_h : %d \n", answer, max_h);
        //print_h(n,m);
        max_h--;
    }

    printf("%d \n", answer);

    return 0;
}
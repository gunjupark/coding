#include <iostream>

using namespace std;

bool A[102][102] = {false};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


int main(){

    int N;
    cin >>N;

    int x, y;

    for (int n=0; n< N; n++){
        cin >> x >> y;

        for (int i=y; i <y+10; i++){
            for (int j=x; j < x+10; j++){
                if(!A[i][j]){
                    A[i][j]=true;
                }
            }
        }
    }

    int ans =0;

    for (int i=1; i<100; i++){
        for (int j=1; j<100; j++){
            if(A[i][j]){
                for (int k=0; k<4; k++){
                    if(!A[i+dy[k]][j+dx[k]]){
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

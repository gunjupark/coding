#include <iostream>
#include <vector>
//#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int dir[5] = {-1, 1, 3, 0, 2}; // dx 와 매칭


int dx[]= {0,1,0,-1}; // 남 동 북 서
int dy[]= {1,0,-1,0};


// 반시계방향 회전 : dx[(i+1)%4]
// 시계방향 회전 : dx[(4+i-1)%4]

int main(){
    int M, N; // M : height, N : width;
    cin >> M >> N;

    vector< vector<int> > A(M,vector<int>(N));

    vector< vector<int> > dist(M,vector<int>(N,0));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    int sy,sx,sd; // start
    int gy,gx,gd; // goal

    cin >> sy >> sx >> sd;

    cin >> gy >> gx >> gd;
    // tuple : y+1, x+1, dir_index
    queue<tuple<int,int,int> > q;

    q.push(make_tuple(sy-1, sx-1, dir[sd] ));


    while(!q.empty()){

        tuple<int,int,int> state = q.front();

        int x = get<1>(state), y = get<0>(state), cur_d =get<2>(state);

        // goal state 처리
        // 시계, 반시계, 뒤돌기 수행 수 방향 일치하면 answer 출력
        if (x == gx && y == gy){
            //직진 : +0
            if(cur_d == dir[gd]){
                cout << dist[y][x] << "\n";
                return 0;
            }

            // 반시계 : +1
            if(dx[(cur_d+1)%4] == dx[dir[gd]] && dy[(cur_d+1)%4] == dy[dir[gd]] ){
                cout << dist[y][x]+1 << "\n";
                return 0;
            } 

            // 시계 : +1
            if(dx[(cur_d+3)%4] == dx[dir[gd]] && dy[(cur_d+3)%4] == dy[dir[gd]] ){
                cout << dist[y][x]+1 << "\n";
                return 0;
            } 

            // 뒤돌기 : +2
            if(dx[(cur_d+2)%4] == dx[dir[gd]] && dy[(cur_d+2)%4] == dy[dir[gd]] ){
                cout << dist[y][x]+2 << "\n";
                return 0;
            } // 반시계
        }

        // 반시계방향 회전 : dx[(cur_dir+1)%4], dy
        // 시계방향 회전  : dx[(cur_dir+3)%4], dy
        // 회전 0(직진)  , 회전 1 (좌,우) , 회전 2(뒤돌기)[필요없음?]
        // 전진 1, 2, 3

        //dir : 동1 서2 남3 북4

        int nx, ny, nd;
        // 회전 0(직진)
        for(int i=1; i <=3; i++){
            nd = cur_d;
            nx = x + i*dx[nd];
            ny = y + i*dy[nd];
            if(nx >=0 && nx < N && ny >=0 && ny <M){
                if(dist[ny][nx] == 0 && A[ny][nx]!=1){
                    q.push(make_tuple(ny, nx, nd));
                    dist[ny][nx] = dist[y][x]+1;
                }
            }
        }
        

        // 시계
        for(int i=1; i <=3; i++){
            nd = (cur_d+1)%4;
            nx = x + i*dx[nd];
            ny = x + i*dy[nd];
            if(nx >=0 && nx < N && ny >=0 && ny <M){
                if(dist[ny][nx] == 0 && A[ny][nx]!=1){
                    q.push(make_tuple(ny, nx, nd));
                    dist[ny][nx] = dist[y][x]+2;
                }
            }
        }
        //반시계
        for(int i=1; i <=3; i++){
            nd = (cur_d+3)%4;
            nx = x + i*dx[nd];
            ny = x + i*dy[nd];
            if(nx >=0 && nx < N && ny >=0 && ny <M){
                if(dist[ny][nx] == 0 && A[ny][nx]!=1){
                    q.push(make_tuple(ny, nx, nd));
                    dist[ny][nx] = dist[y][x]+2;
                }
            }
        }

        // 뒤돌기는 필요없을듯?


    }

    tuple<int,int,int> state = q.front();


    return 0;
}

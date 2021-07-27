#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int a[50][50];

int check[50][50];
int max_size = 0;

int n, m;

/*
void print_map(){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf(" %d ", check[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
*/

int dfs(int y, int x, int r_id){
    
    check[y][x] = r_id;

    int res = 1;

    int w = a[y][x];
    //bitmask - binary
    int nx, ny;
    //printf("w : %d \n",w);
    for(int i=0; i<4; i++){
        if(!(w & (1<<i))){
            //printf("no wall i : %d \n",i);
            nx = x+dx[i];
            ny = y+dy[i];
            //boundary cond + check
            if(nx >=0 && nx < n && ny >=0 && ny < m){
                if(check[ny][nx] == -1)
                    res += dfs(ny, nx, r_id);
            }
        }
    }

    return res;
}

void cal_max_room(int y, int x, vector<int> &r_sizes){
    int s = r_sizes[check[y][x]];
    int w = a[y][x];
    int nx, ny;
    for (int i=0; i<4; i++){
        if(w & (1<<i)){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx >=0 && nx < n && ny >=0 && ny < m){
                if(check[y][x] != check[ny][nx]){
                    if(max_size < s + r_sizes[check[ny][nx]]){
                        max_size = s+ r_sizes[check[ny][nx]];
                    }
                }
            }
        }
    }
    return;
}


int main() {
    cin >> n >> m;

    memset(check, -1, sizeof(check));

    int room_id =0;

    vector<int> room_sizes;

    for (int i= 0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }


    for (int i=0; i< m; i++){
        for (int j=0; j<n; j++){
            if(check[i][j] == -1){
                room_sizes.push_back(dfs(i,j, room_id));
                room_id++;
            }
        }
    }
    // 벽 부술때, 최대 방 크기
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cal_max_room(i, j, room_sizes);
        }
    }

    //print_map();

    printf("%d\n", room_id);
    printf("%d\n", *max_element(room_sizes.begin(), room_sizes.end()));
    printf("%d\n", max_size);

    return 0;
}
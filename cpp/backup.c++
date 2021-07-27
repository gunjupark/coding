#include <vector>
#include <queue>
#include <memory.h>


using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int solution(vector<vector<int> > board)
{
    int answer = 0;
    
    //vector<vector<int>> dist(4,vector<int>(4, -1));
    
    int dist[4][4];
    memset(dist, -1, sizeof(dist));
    
    queue<pair<int,int>> q;
    
    for(int i=0; i<4; i++){ // row
        for(int j=0; j<4; j++){ // col
            //q = queue<pair<int,int>>();
            memset(dist, -1, sizeof(dist));
            
            dist[i][j] = 1;
            q.push(make_pair(i,j));
            
            while(!q.empty()){
                auto tmp = q.front();
                q.pop();
                
                int x = tmp.second, y = tmp.first;
                int nx,ny;
                int color = board[y][x];
                
                for (int k=0; k<4; k++){
                    nx = x+dx[k];
                    ny = y+dy[k];
                    if(nx < 4 && nx >=0 && ny <4 && ny >=0){
                        if(dist[ny][nx] == -1 && color == board[ny][nx]){
                            q.push(make_pair(ny,nx));
                            dist[ny][nx] = dist[y][x] +1;
                            if(dist[ny][nx] > answer) answer = dist[ny][nx];
                        }
                    }
                }
            }// while loop end
        }
    }// r, c for loop end
    
    if(answer < 2) return -1;
    
    return answer;
}


#include<vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > monsters, vector<vector<int> > bullets)
{
    if(monsters.empty()) return -1;
    if(bullets.empty()) return -1;
    
    int N = monsters.size();
    int M = bullets.size();
    
    int answer = 0;
    
    for (int i=0; i < N; i++){ // monsters
        for (int j=0; j< M; j++){ // bullets
            if(monsters[i][0] ==0 && bullets[j][0] ==0){
                if(monsters[i][1]>0 && bullets[j][1] >0){
                    answer++;
                    break;
                }
                if(monsters[i][1]<0 && bullets[j][1] <0){
                    answer++;
                    break;
                }
            
            }
            if(monsters[i][1] ==0 && bullets[j][1] ==0){
                if(monsters[i][0]>0 && bullets[j][0] >0){
                    answer++;
                    break;
                }
                if(monsters[i][0]<0 && bullets[j][0] <0){
                    answer++;
                    continue;
                }
            
            }
            if(monsters[i][0] !=0){
                float ratio = (bullets[j][0] / monsters[i][0]);
                if(monsters[i][1] != 0 || bullets[j][0] != 0 || bullets[j][1] !=0){
                    if((int)(monsters[i][1] * ratio) == bullets[j][1]){

                        answer ++;
                        break;
                    }
                }
            }
        }
    }
    
    
    return answer;
}

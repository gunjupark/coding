#include <iostream>
#include <vector>

// int dx[]={1,-1,0,0};
// int dy[]={0,0,1,-1};

using namespace std;

int main(){

    int k;
    cin >>k;

    int dir[6], len[6];
    int max_w=0,max_h=0;
    int sub_w,sub_h;


    int d_cnt[4]={0,};
    for (int i=0; i<6; ++i){
        cin >> dir[i] >> len[i];

        // if (dir[i] ==1 || dir[i] ==2){
        //     max_w = (max_w <= len[i]) ? len[i] : max_w;
        // }


        // if(dir[i] ==3 || dir[i] ==4){
        //     max_h = (max_w <= len) ? len : max_h;
        // }

        if(dir[i] ==1 ){
            d_cnt[dir[i]-1]++;

            max_w = (max_w <= len[i]) ? len[i] : max_w;

        }
        if(dir[i] ==2 ){
            d_cnt[dir[i]-1]++;

            max_w = (max_w <= len[i]) ? len[i] : max_w;

        }
        if(dir[i] ==3 ){
            d_cnt[dir[i]-1]++;

            max_h = (max_h <= len[i]) ? len[i] : max_h;

        }
        if(dir[i] ==4 ){
            d_cnt[dir[i]-1]++;

            max_h = (max_h <= len[i]) ? len[i] : max_h;

        }
    }

    // ㄱ
    if(d_cnt[0]==2 && d_cnt[2]==2){
        int i=0;
        while(true){
            if(dir[i%6]==1 && dir[(i+1)%6] ==3){
                sub_h= len[i%6];
                sub_w= len[(i+1)%6];
                break;
            }
            i++;
        }
    }
    //┏
    if(d_cnt[0]==2 && d_cnt[3]==2){
        int i=0;
        while(true){
            if(dir[i%6]==4 && dir[(i+1)%6] ==1){
                sub_h= len[i%6];
                sub_w= len[(i+1)%6];
                break;
            }
            i++;
        }
    }

    //┗
    if(d_cnt[1]==2 && d_cnt[3]==2){
        int i=0;
        while(true){
            if(dir[i%6]==2 && dir[(i+1)%6] ==4){
                sub_h= len[i%6];
                sub_w= len[(i+1)%6];
                break;
            }
            i++;
        }
    }
    //┛
    if(d_cnt[1]==2 && d_cnt[2]==2){
        int i=0;
        while(true){
            if(dir[i%6]==3 && dir[(i+1)%6] ==2){
                sub_h= len[i%6];
                sub_w= len[(i+1)%6];
                break;
            }
            i++;
        }
    }

    int size = (max_w * max_h) - (sub_w * sub_h);

    cout << size * k << "\n";



    return 0;
}
#include <iostream>
#include <string>

using namespace std;


int A[] = {4,5,1,7,9,2,6};

char path[4];

void go(int idx, int cnt){
    if(idx >7) return;
    if(cnt ==3){
        for (int i=0; i <3; ++i){
            cout <<path[i];
        }
        cout <<"\n";
        return;
    }

    path[cnt] = (char)('0'+A[idx]);
    go(idx+1, cnt+1);
    path[cnt] = 0;

    go(idx+1, cnt);

}

int main(){

    go(0,0);

    return 0;
}
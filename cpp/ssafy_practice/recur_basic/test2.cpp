#include <iostream>

using namespace std;


int tmp[] = {3,7,5,9,8,7};
int ord[] = {2,3,1,5,-1,4};


void go(int idx){
    if(idx==4){
        cout << tmp[idx] << " ";
        return;
    }


    cout << tmp[idx] << " ";
    if(idx==0){
        go(2);
    }
    else if(idx ==1){
        go(3);
    }
    else if(idx == 2){
        go(1);
    }
    else if (idx == 3){
        go(5);
    }
    else if(idx==5){
        go(4);
    }
    cout << tmp[idx] << " ";

    return;
}

int main() {

    go(0);
    return 0 ;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int A[] = {3,5,1,9,7};

char inputs[5];

int mov = 0;

void go(int idx){
    if(idx==4) return;

    if(inputs[idx]=='L') mov--;
    else mov++;

    go(idx+1);

    return;
}

void rotate_print(){
    int res[6];
    for (int i=0; i<5; ++i){
        res[(i+5+mov)%5] = A[i];
    }

    for (int i=0; i <5; ++i){
        cout << res[i] <<" ";
    }
    cout <<"\n";

    return;
}


int main(){
    char ch;
    for (int i=0; i <4; ++i){
        cin >> ch;
        inputs[i] = ch;
    }
    
    go(0);
    rotate_print();
    printf("%d \n", mov);
    return 0;
}
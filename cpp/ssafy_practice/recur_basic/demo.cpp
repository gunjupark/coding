#include <iostream>

using namespace std;

int n;

int A[3][2][2] = {
    {{2,4},
     {1,5}},
    {{2,3},
     {3,6}},
    {{7,3},
     {1,5}}
};

int max_v= 0, min_v= 99999999;

void go(int idx){
    if(idx==4){
        cout <<"MAX="<<max_v <<"\n";
        cout <<"MIN="<<min_v <<"\n";
        return;
    }

    if(max_v < A[n][idx/2][idx%2]){
        max_v = A[n][idx/2][idx%2];

    }
    if(min_v > A[n][idx/2][idx%2]){
        min_v = A[n][idx/2][idx%2];
    }
    go(idx+1);
    return;
}


int main(){
    cin >> n;
    go(0);
    return 0;
}
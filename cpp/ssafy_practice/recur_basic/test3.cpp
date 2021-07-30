#include <iostream>

using namespace std;


int tmp[] = {3,2,1,2,5,3,2,1};

int num[10];

void go(int idx){
    if(idx ==8) return;

    num[tmp[idx]]++;
    go(idx+1);

    return;
}

int main(){
    go(0);
    for (int i=0; i < 10; ++i){
        if(num[i] !=0){
            cout << i << " : "<<num[i] << "개 \n";
        }
    }

    return 0;
}
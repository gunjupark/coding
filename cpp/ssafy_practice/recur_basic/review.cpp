#include <iostream>
#include <string>
using namespace std;


void go(int idx, int sum, string tmp){
    if(sum>10){
        return;
    }
    if(idx ==4){
        for(int j=0; j<4; ++j){
            if(j==3){
                cout << tmp[j] << " = ";
            }
            else{
                cout << tmp[j] << " + ";
            }

        }
        cout << sum << "\n";
        return;
    }

    for (int i=1; i<=6; ++i){
        go(idx+1, sum+i, tmp + to_string(i));
    }

    return;
}

int main(){

    go(0, 0, "");

    return 0;
}
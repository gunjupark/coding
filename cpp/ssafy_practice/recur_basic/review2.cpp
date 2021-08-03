#include <iostream>
#include <vector>
#include <string>

using namespace std;



int tmp[] = {11,5,7,4,9};
bool check[5];

void go(int idx, int prev, string bt){
    if(idx ==4){
        cout << bt << "\n";
        return;
    }

    for (int i=0; i < 5; ++i){
            if((tmp[i] + prev) >=15){
                continue;
            }
            go(idx+1, tmp[i], bt+to_string(tmp[i]));
    }

    return;
}


int main(){

    go(0,0,"");
    return 0;
}
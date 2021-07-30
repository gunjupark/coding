#include <iostream>
#include <vector>
#include <string>

using namespace std;

char path[10];
int used[4];

void go1(int idx){
    if(idx >0 && path[idx-1] =='B') return;

    if(idx == 3 && path[idx-1]!=' '){
        cout << path << endl;
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if(!used[i]){
            used[i]= true;
            path[idx] = 'A'+i;
            go1(idx+1);
            path[idx] =' ';
            used[i] = false;
        }
        go1(idx+1);
    }
    return;
}

int main(){
    
    go1(0);

    return 0;
}
#include <iostream>
#include <string>
#include <set>

using namespace std;

enum Roman
{
    I = 1,
    V = 5,
    X = 10,
    L = 50
};

int len;

void go(set<int> &s, int idx, int sum){
    if(idx == len){
        s.insert(sum);
    }

    go(s, idx+1, sum+ I);
    go(s, idx+1, sum+ V);
    go(s, idx+1, sum+ X);
    go(s, idx+1, sum+ L);

    return;
}

int main(){

    set<int> s;

    go(s, 0, 0);

    cout << s.size() << "\n";

    return 0;
}
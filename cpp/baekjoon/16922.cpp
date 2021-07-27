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

void go(set<int> &s, int idx, int prev, int sum){
    if(idx == len){
        s.insert(sum);
        return;
    }

    if(prev <= I) go(s, idx+1, I, sum+ I);
    if(prev <= V) go(s, idx+1, V, sum+ V);
    if(prev <= X) go(s, idx+1, X, sum+ X);
    go(s, idx+1, L, sum+ L);

    return;
}

int main(){

    cin >> len;
    set<int> s;

    go(s, 0, I, 0);

    cout << s.size() << "\n";

    return 0;
}
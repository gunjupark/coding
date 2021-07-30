#include <iostream>
#include <string>

using namespace std;

void go(int n, string s){
    if(s.size() ==n){
        cout << s <<"\n";
        return;
    }

    go(n, s+'L');
    go(n, s+'R');
    return;
}

int main(){
    int n;
    cin >> n;

    go(n, "");
    return 0;
}
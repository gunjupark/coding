#include <iostream>
#include <string>


using namespace std;

void go(int n, string s){

    if(s.size()==n){
        cout <<s<<"\n";
        return;
    }

    go(n, s+'O');
    go(n, s+'X');

    return;
}

int main(){
    int n;
    cin >>n;

    go(n,"");

    return 0;
}
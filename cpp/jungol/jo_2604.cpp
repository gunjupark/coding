#include <string>
#include <iostream>

using namespace std;


int main() {
    string s;
    cin >> s;

    //char first = s[0];
    int ans =10;
    for (int i=1; i<s.size(); i++){
        if(s[i-1] == s[i]){
            ans += 5;
        }
        else{
            ans +=10;
        }
    }

    cout << ans <<"\n";

    return 0;
}
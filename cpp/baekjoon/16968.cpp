#include <iostream>
#include <vector>
#include <string>


using namespace std;



int go(string &s, int idx, char last){

    if(idx == s.size()){
        return 1;
    }
    char start = (s[idx] == 'c' ? 'a':'0');
    char end = (s[idx] == 'c' ? 'z':'9');
    int ans =0;
    for(char i=start; i<end; i++){
        if(i == last) continue;
        ans += go(s,idx+1, i);
    }

    return ans;
}


int main(){
    string s;
    cin >> s;
    //getline(cin, s);

    cout << go(s, 0, ' ') << '\n';

    return 0;
}
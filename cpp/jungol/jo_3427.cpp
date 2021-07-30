#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

bool checkRB(string rb){
    char c1 = rb[0];
    char c2 = (c1 =='R') ? 'B' : 'R';
    int cnt = count(rb.begin(), rb.end(), c1);

    if (rb.substr(cnt).find(c2) == -1){
        return true;
    }

    return false;
}

int main(){
    int N;
    cin >> N;


    string rb;
    cin >> rb;

    // 색이 한가지인 경우 & N<2 (예외처리)
    if(rb.find("R")==-1 || rb.find("B")== -1 || N <3) {
        cout << 0;
        return;
    }

    // 각 

    return 0;
}
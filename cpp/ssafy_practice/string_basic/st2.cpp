#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "ABCOOOABCOOOOOOABCABC";

    //ABC 다 찾아서
    //KFCWORLD 라는 문자열로 전부 교체 replace

    while(1){
        int s = str.find("ABC", s);
        if(s == -1 ) break;
        str.erase(s,3);
        str.insert(s,"KFCWORD");

        s +=3;
    }

    cout << str;

    return 0;
}
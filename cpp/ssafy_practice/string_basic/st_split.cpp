#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "ABO|OOO|ABCAB|C";
    string table[4];

    // '|' bar를 기준으로 문자열들을 파싱하여 
    //각 테이블 index에 순서대로 채워넣기

    //table[0] = ABO
    //table[1] = OOO
    //...

    int s=0,e, i=0;
    while(true){
        e = str.find('|',s);
        if(e == -1 || i >4){
            table[i] = str.substr(s);
            break;
        }

        table[i] = str.substr(s,e-s);
        
        s = e+1;
        i++;

    }

    for (size_t i = 0; i < 4; i++)
    {
        cout << table[i] << "\n";
    }
    

    return 0;
}
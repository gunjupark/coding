#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "QWE[1234]TR[1000][3000]BBQ[4321]AA";

    //괄호 안에 있는 수들의 전체 합 출력 (정답 : 9,555)

    int ans =0;
    while(1){
        int a = str.find('[',a);
        if(a == -1) break;
        int b = str.find(']',a+1);

        int tmp = stoi(str.substr(a+1,b-a-1));
        ans += tmp;
        a = b+1;
    }

    cout << ans <<"\n";

    return 0;
}
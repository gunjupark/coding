#include <iostream>
#include <string>
using namespace std;

string id;

int main()
{
    //id가 3 ~ 8 글자 까지 허용 (3, 8 포함)
    //id에 영어 대소문자만 허용
    //첫글자는 대문자로 시작해야함

    cin >> id;

    if(id.size() < 3 || id.size() >8) {
        cout << "NO INVALID \n";
        return 0;
    }
    if(id[0] > 'Z' || id[0] <'A'){
        cout << "NO INVALID \n";
        return 0;
    }

    for (size_t i = 1; i < id.size(); i++)
    {
        if(!((id[i] < 'Z' && id[0] >'A') || (id[i] >'a' && id[i]<'z'))){
            cout << "NO INVALID \n";
            return 0;
        }

    }
    
    cout << "OK VALID \n";
    

    //출력결과 (둘중 하나 출력)
    //OK VALID
    //NO INVALID

    return 0;
}
//등급 (오늘 날짜 30일 이내에)
//브론즈 : 0 ~ 10000 미만 구매 고객
//실버 : 10000 이상 50000 미만 구매 고객
//골드 : 50000 이상 구매 고객

//구매 날짜 입력

#include <iostream>
#include <string>

using namespace std;

//오늘날짜는 2021/07/28
int n = 3;
string input[3] = { "2021/07/05 5000", "2021/07/18 10000", "2021/06/04 60000" };


int main()
{
    int sum = 0;

    int s=0, e, k=0;

    string target ="2021/07/28";
    string tar_arr[3];
    target +='/';
    while(true){
            e = target.find('/',s);
            if(e == -1 || k>=3) break;

            tar_arr[k++] = target.substr(s,e-s-1);
            s = e+1;
    }


    for (int i=0; i<n; i++){
        string tmp = input[i];
        string arr[4];
        int blank_idx = tmp.find(' ');
        string a = tmp.substr(0,blank_idx) + '/';
        //arr = 년도, 월, 일, 가격
        arr[3] = tmp.substr(blank_idx+1);
        s=0; e=0; k=0;
        while(true){
            e = a.find('/',s);
            if(e == -1 || k >=3) break;

            arr[k++] = a.substr(s,e-s-1);
            s = e+1;
        }

        if (arr[0] == tar_arr[0] && arr[1] == tar_arr[1] && stoi(arr[2]) < stoi(tar_arr[2]) ) {
            sum += stoi(arr[3]);
        }
    }

    if(sum < 10000 && sum >= 0){
        cout << "브론즈 등급 \n";
        cout << sum << "\n";
    }
    else if (sum >=10000 && sum < 50000){
        cout << "실버 등급 \n";
        cout << sum << "\n";
    }
    else if( sum >=50000){
        cout << "골드 등급 \n";
        cout << sum << "\n";
    }
    //이 회원의 등급이 무엇인지 출력하는 문제    
    //출력결과 : 브론즈 등급
    
    //조건 1 : 0000/00/00 포맷으로 날짜가 입력됨
    //조건 2 : 한달은 무조건 30일로 간주 (31일, 28, 29일은 고려하지 않음)
    //조건 3 : invalid 한 입력데이터는 주어지지 않음

    return 0;
}
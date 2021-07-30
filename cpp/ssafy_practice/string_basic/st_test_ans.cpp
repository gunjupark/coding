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

int getPoint(string str)
{
    int line = str.find(' ');
    string date = str.substr(0, line);
    string money = str.substr(line + 1);

    int a = date.find('/');
    string temp = date.substr(0, a);
    int year = stoi(temp);

    int b = date.find('/', a + 1);
    temp = date.substr(a + 1, b - a - 1);
    int mon = stoi(temp);

    int c = date.find('/', b + 1);
    temp = date.substr(b + 1, c - b - 1);
    int day = stoi(temp);

    int num = (year * 12 * 30) + (mon * 30) + day;
    int today = 2021 * 12 * 30 + 7 * 30 + 28;

    if (today - num > 30) return 0;

    int my = stoi(money);

    return my;
}

int main()
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += getPoint(input[i]);
    }

    cout << sum;
    

    //이 회원의 등급이 무엇인지 출력하는 문제    
    //출력결과 : 실버 등급
    
    //조건 1 : 0000/00/00 포맷으로 날짜가 입력됨
    //조건 2 : 한달은 무조건 30일로 간주 (31일, 28, 29일은 고려하지 않음)
    //조건 3 : invalid 한 입력데이터는 주어지지 않음

    return 0;
}
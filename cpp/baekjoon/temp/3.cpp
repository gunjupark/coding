#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

vector<string> solution(int n, int k, vector<string> cmd){

    vector<string> answer(n, 'O'); // O로 초기화된 정답 배열 (길이 : n)

    int cur = k;
    stack<int> s;

    // 문제조건 단순 : boundary , empty 체크 필요없음
    for(string c : cmd){
        if(cmd[0] == 'U'){
            cur = cur - atoi(cmd[2].c_str()); // boundary 체크 필요없음
        }
        if(cmd[0] == 'D'){
            cur = cur + atoi(cmd[2].c_str()); // boundary 체크 필요없음
        }
        if(cmd[0] == 'C'){
            answer[cur] = 'X';
            s.push(cur);
        }
        if(cmd[0] == 'Z'){
            // stack empty 체크 필요없음
            answer[s.top()] = 'O';
            s.pop();
        }
    }

    return answer;
}

int main() {

    

    return 0;
}
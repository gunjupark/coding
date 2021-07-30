#include <iostream>
#include <string>
#include <vector>


using namespace std;

bool check[1000];

int main(){

    // candidate 추리기
    for (int i=0; i< 123; ++i){
        check[i] = true;
    }
    for (int i=988; i<1000; ++i){
        check[i] = true;
    }
    for (int i=123; i < 988; ++i){
        string tmp = to_string(i);
        if(tmp[0] - '0' == 0 || tmp[1] - '0' ==0 || tmp[2] - '0' == 0){
            check[i] = true;
            continue;
        }
        if(tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]){
            check[i] = true;
        }
    }

    int N;
    cin >>N;

    vector<vector<int> > A(N, vector<int>(3));

    for(int i=0; i<N; ++i){
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    // baseball check
    for (int i=123; i <988; ++i){
        if(check[i]) continue;
        
        string num1 = to_string(i);

        for (int j=0; j < N; ++j){
            string num2 = to_string(A[j][0]);
            int s = A[j][1];
            int b = A[j][2];

            int cur_s=0,cur_b=0;

            for (int a=0; a<3; ++a){
                for (int b=0; b<3; ++b){
                    if(num1[a] == num2[b] && a ==b){
                        cur_s++;
                    }
                    else if (num1[a] == num2[b] && a != b){
                        cur_b++;
                    }
                }

            }

            if(cur_s != s || cur_b !=b){
                check[i] = true;
            }

        }

    }

    int answer =0;

    for (int i=0; i < 1000; ++i){
        if(!check[i]){
            answer++;
        }
    }

    cout << answer <<"\n";

    

    return 0;
}
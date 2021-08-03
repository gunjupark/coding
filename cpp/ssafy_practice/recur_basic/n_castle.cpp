#include <iostream>

using namespace std;
//#include <vector>

bool chk_row[10];
bool chk_col[10];

int N;

int go(int cnt){
    int answer =0;

    if(cnt == N){
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
            for (int j = 0; j < N; j++)
            {
                if(!chk_col[j]){
                    chk_col[j] = true;
                    answer += go(cnt+1);
                    chk_col[j] = false;
                }
            }
        }
    }
    return answer;
}

int main(){
    cin >> N;

    int ans = go(0);
    cout << ans <<"\n";

    return 0;
}







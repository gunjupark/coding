#include <iostream>
#include <vector>

using namespace std;

char path[26];
bool check[26];

int n;


void go(int idx, vector<char> &A){
    
    if(idx == n){
        for (int i=0; i<n; ++i){
            cout << path[i] << " ";
        }
        cout << "\n";

        return;
    }

    for (int i=0; i< A.size(); ++i){
        if(!check[A[i]-'A']){
            //if(abs(path[idx-1]-A[i])==1) continue;
            // 위 방법 또는 아래방식
            if(abs(path[idx-1]-A[i]) != 1){
                path[idx] = A[i];
                check[A[i]-'A'] = true;
                go(idx+1, A);
                path[idx] = 0; // 가독성 용
                check[A[i]-'A'] = false;
            }
        }
    }

    return ;
}


int main() {
    cin >> n;
    vector<char> A(n);
    for (int i=0; i < n; ++i){
        cin >> A[i];
    }

    for (int i=0; i < n; ++i){
        check[A[i]-'A'] =true;
        path[0]  = A[i];
        go(1,A);
        check[A[i] - 'A'] =false;
        path[0] = 0;
    }

    return 0;
}
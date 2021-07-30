#include <string>
#include <iostream>
#include <vector>


using namespace std;

int main(){

    string a,b;
    int div_size= 10;

    while(!cin.eof()){
        vector<string> A;
        vector<string> B;
        cin >> a >> b;

        for (int i=a.size()-1; i>=0; i-=10){
            if(i-10 < 0){
                A.push_back(a.substr(0,i-1));
            }
            else{
                A.push_back(a.substr(i-10,10));
            }
        }

        for (int i=b.size()-1; i >= 0; i-=10){
            if(i-10 < 0){
                B.push_back(b.substr(0, i-1));
            }
            else{
                B.push_back(b.substr(i-10,10));
            }
        }

        cout << a << "\n" << b <<"\n";

        for (auto aa : A){
            cout << aa << " ";
        }
        cout << "\n";
        for (auto bb : B){
            cout << bb << " ";
        }
        cout << "\n";


        // 10글자 단위 (long long) - proto
        int len_a = a.size(), len_b = b.size();

        // 대소 비교 후 스왑
        string tmp;
        if(len_a < len_b || (len_a == len_b && a[0] < b[0]) ){
            tmp = a;
            a = b;
            b = tmp;
        }

        string ans;
        int overflow = 0;
        // 덧셈
        for(int i=0; i < B.size(); i++){
            long long num_a, num_b, num_c;
            num_a = stoll(A[i]);
            num_b = stoll(B[i]);
            num_c = num_a + num_b + overflow;
            if(to_string(num_c).size() ==11) overflow=1;
            else overflow =0;

            ans = to_string(num_c) + ans;
        }
        if (ans.size() > a.size()){
            ans = '1'+ans;
        }

        cout << ans << "\n";
    }


    return 0;
}
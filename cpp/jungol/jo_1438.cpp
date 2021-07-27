#include <iostream>

using namespace std;


bool A[101][101] = {false,};


int main(){

    //    freopen_s(new FILE*, "", "r", stdin);
    int N;
    cin >> N;

    int ans = 0;
    int x, y;
    for (int i=0; i < N; i++){
        cin >> x >> y;
        for (int j=y; j<y+10; j++){
            for (int k=x; k <x+10; k++ ){
                if(!A[j][k]){
                    A[j][k] = true;
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
    return ans;

}
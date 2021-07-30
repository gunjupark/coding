#include <iostream>
#include <vector>

using namespace std;

int main(){
    int d, k;

    cin >> d >> k;

    vector<int> fibo(30);

    fibo[0] = 1;
    fibo[1] = 1;
    for (int i=2; i<30; i++){
        fibo[i] = fibo[i-1]+fibo[i-2];
    }
    // k = fibo[d-3]*a + fibo[d-2]*b

    for (int i=1; i<=k/fibo[d-3]; i++){
        if((k- i*fibo[d-3]) % fibo[d-2] ==0){
            cout << i << "\n" << (k-i*fibo[d-3])/fibo[d-2] <<"\n";
            break;
        }
    }


    return 0;
}
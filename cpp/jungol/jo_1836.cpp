#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);

    for (int n=0; n<N; n++){
        cin >> A[n];
    }

    int psum=0;
    int pmax=-100;
    for (int i=0; i<N; i++){
        psum = (psum+A[i] <0) ? 0 : psum + A[i];

        pmax = (pmax < psum) ? psum : pmax;
    }

    cout << pmax <<"\n";

    return 0;
}
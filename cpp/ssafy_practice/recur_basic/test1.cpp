#include <iostream>

using namespace std;

int A[5] = {4,7,9,1,5};

void go(int x ){

    if (x==1){
        cout << x << " ";
        return;
    }

    cout << x << " ";
    go(x-1);
    cout << x << " ";

    return;
}

void go2(int idx){
    if(idx == 4){
        cout << A[idx] << " ";
        return;
    }

    cout << A[idx] << " ";
    go2(idx+1);
    cout << A[idx] << " ";

    return;
}

// 누적합
void go3(int idx, int sum){ 

    sum += A[idx];
    if(idx ==4){
        cout << sum << " ";
        return;
    }
    cout << sum << " ";
    go3(idx+1, sum);
    cout << sum << " ";

    return;
}

int main(){
    int n;
    cin >> n;
    go(n);
 
    go2(0);
    
    go3(0,0);

    return 0;
}
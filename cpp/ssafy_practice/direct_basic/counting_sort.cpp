#include <iostream>

using namespace std;

int a[] = {1,3,1,5,7,4,5};

int bucket[10];


int main(){
    //direct table
    for (int i=0; i < 7; ++i){
        bucket[a[i]]++;
    }
    // partial sum
    for (int i=1; i<10; ++i){
        bucket[i]+= bucket[i-1];
    }

    int res[10];

    for (int i=0; i < 7; ++i){
        res[bucket[a[i]]] = a[i];
        bucket[a[i]]--;
    }

    for (int i=0; i<10; ++i){
        cout << res[i] <<" ";
    }
    cout << "\n";

    return 0;
}
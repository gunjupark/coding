#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){


    vector<string> A;

    for (int i=0; i <5; i++){
        string s;
        cin >> s;
        if(s.size() < 15){
            while(s.size()!=15){
                s+=" ";
            }
        }
        A.push_back(s);
    }

    for (int i=0; i<15; ++i){ //col
        for(int j=0; j<5; ++j){ //row
            if(A[j][i] != ' '){
                cout <<A[j][i];
            }
        }
    }
    cout <<"\n";

    return 0;
}
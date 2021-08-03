#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> G;


void go(string s){
    if(s.size()==3){
        G.push_back(s);
        return;
    }
    // for (int i=0; i <4; ++i){
    
    //     go(s+(char)('A'+i));
    // }

    for(char ch='A'; ch <='D'; ++ch){
        go(s+ch);
    }

    return;
}

int main(){
    string in;
    cin >> in;

    go("");
    
    for (size_t i = 0; i < G.size(); i++)
    {
        if(G[i] == in){

            cout << i+1 <<"번째\n";
            break;
        }
    }
    


    return 0;
}
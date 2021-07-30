#include <iostream>
#include <vector>
#include <string>

using namespace std;

void go(int x){
    if(x==0) {
        cout << x << " ";
        return;
    }

    cout << x << " ";
    go(x-1);
    cout << x << " ";
    return;
}

void go2(vector<int> &a, int idx){

    if(idx==a.size()-1){
        cout << a[idx] << " ";
        return;
    }

    cout << a[idx] << " ";
    go2(a, idx+1);
    cout << a[idx] << " ";
    
    return;
}

int tmp[] = {3,7,4,1,9,4,6,2};

void go3(int idx){
    if(idx >7) {
        cout << "ERROR\n";
    }
    if(idx == 0){
        cout << tmp[idx] << " ";
        return;
    }

    cout << tmp[idx] << " ";
    go3(idx-1);
    cout << tmp[idx] << " ";
}

void go4(int n){

    if(n==0) return;

    go4(n/2);
    cout <<n << " ";

    return;
}

void go5(int a, int b){

    if(a == b){
        cout << a <<" ";
        return;
    }

    cout << a << " ";
    go5(a+1,b);
    cout << a << " ";



    return;
}

void go6(int x,int idx){
    if(idx==3){
        cout << x <<" ";
        return;
    }

    go6(x + 2 , idx+1);
    cout << x <<" ";
    return;
}

void go7(string s, int idx){

    if (idx==s.size()){
        cout <<"\n";
        return;
    }
    
    cout << s[idx];
    go7(s,idx+1);
    cout << s[idx];

    return;
}

int main(){
    // int n;
    // cin >> n;

    // go(n);

    // vector<int> a;
    // while(!cin.eof()){
    //     int aa;
    //     cin >> aa;
    //     a.push_back(aa);
    // }
    // go2(a,0);
    // int n;
    // cin >> n;
    // go4(n);

    // int a, b;
    // cin >> a >> b;
    //go6(n,0);
    string s;
    cin >>s;
    go7(s,0);


    return 0;
}
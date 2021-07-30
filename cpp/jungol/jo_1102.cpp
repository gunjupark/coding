#include <stack>

using namespace std;

int main(){

    stack<int> s;

    int N;
    cin >> N;

    char a;
    int b;
    for (int i =0; i < N; ++i){
        cin >> a;
        if (a == 'i'){
            cin >> b;
            s.push(b);
        }
        if(a == 'c'){
            cout << s.size() <<"\n";
        }
        if(a == 'o'){
            if(s.empty()){
                cout << "empty\n"
            }
            else{
                cout << s.front() <<"\n";
                s.pop();
            }
        }
    }



    return 0;
}
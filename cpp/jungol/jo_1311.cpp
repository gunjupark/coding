#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


// 페어 내림차순용
bool compare(const pair<char, int>&a, const pair<char, int>&b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first > b.first;
}



int main() {
    // color order
    // 0:R  1:B  2:G  3:Y
    int c_cnt[4];
    int n_cnt[10];
    

    vector<pair<int,int> > cn(5);
    for (int i=0; i < 5; i++){
        char c;
        int n;
        cin >> c >> n;

        if(c == 'R'){
            cn[i] = make_pair(0,n);
            c_cnt[0]++;
        }
        if(c == 'B'){
            cn[i] = make_pair(1,n);
            c_cnt[1]++;
        }
        if(c == 'G'){
            cn[i] = make_pair(2,n);
            c_cnt[2]++;
        }
        if(c == 'Y'){
            cn[i] = make_pair(3,n);
            c_cnt[3]++;
        }

        for (int j=1; j<10; j++){
            if(j == n){
                n_cnt[j]++;
            }
        }
    }

    sort(cn.begin(), cn.end(), compare);

    int* max_c = max_element(c_cnt, c_cnt+4);
    int* max_n = max_element(n_cnt, n_cnt+10);

    cout << "max_n : " << max_n-n_cnt <<" max_n_value : " << *max_n <<"\n";

    //four card
    if(*max_n ==4){
        cout << 800+ max_n - n_cnt << "\n";
    }

    //flush
    if(*max_c ==5){
        //straight


        //normal
        // else{

        //     cout << 600 + 
        // }
    }


    return 0;
}

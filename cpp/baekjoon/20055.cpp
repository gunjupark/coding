#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n , k;
    cin >> n >> k;

    vector<int> a(2*n);
    for (int i=0; i < 2*n; i++){
        cin >> a[i];
    }
    vector<bool> r(n, false);
    int answer=0;
    int cnt =0;
    while(true){
        answer++;
    // 1) rotate & pull down

        // clock rotate (1)
        rotate(a.rbegin(), a.rbegin()+1, a.rend());
        // clock rotate (2)
        
        
        // robot rotate
        rotate(r.rbegin(), r.rbegin()+1, r.rend());
        
        // robot 내림
        if(r[n-1]) r[n-1]= false;
        r[0] = false; 
        

        
    // 2) forwarding R (only if next's a !=0)
        for (int i=n-2; i >= 0; i--){
            if(r[i]){
                if(r[i+1]==false && a[i+1] >0){
                    r[i+1] = true;
                    r[i]= false;
                    a[i+1] -= 1;
                    if(a[i+1]==0) cnt+= 1;
                }
            }
        }
        // robot 내림 (문제에 애매하게 언급된 부분...)
        if(r[n-1]) r[n-1] = false;
        
    // 3) push up R
        if(a[0]>0) {
            a[0]-= 1;
            r[0] = true;
            if(a[0]==0) cnt+= 1;
        }

    // 4) check  (a==0) count >= K 
        if(cnt >= k){
            printf("%d \n",answer);
            return 0;
        }
    }

    return 0;
}


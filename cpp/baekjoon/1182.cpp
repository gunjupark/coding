#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void go(vector<int> &nums, int s, int sum, int idx){
    int len = nums.size();
    if(idx == len) {
        if(sum == s){
            ans++;
        }
        return;
    }
    
    go(nums, s, sum+nums[idx], idx+1);
    go(nums, s, sum, idx+1);
    
    return;
}

int main() {
    int n, s;
    
    cin >> n >> s;
    
    vector<int> nums(n);
    
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    go(nums,s, 0 , 0);
    
    if (s == 0 ) ans--;
    
    printf("%d\n",ans);
    
    
    return 0;
}



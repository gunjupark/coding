#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define PRINT 1

using namespace std;

pair<long,long> mm_pair = make_pair((long)1000000000,(long)-10000000000);

int ops[4];

void go(vector<int> &nums, long sum, int idx){
	int len = nums.size();
	printf("%ld \n", sum);
	if(idx == len) {
		if(sum < mm_pair.first) mm_pair.first = sum;
		if(sum > mm_pair.second) mm_pair.second = sum;
		return;
	}
	if (ops[0] + ops[1] + ops[2] + ops[3] == 0) return;

	long temp;
	printf("%ld \n", sum);
	if(ops[0] > 0 ){
		temp = sum+nums[idx];
		ops[0] -= 1;
		go(nums, temp, idx+1);
		ops[0] +=1;
	}
	if(ops[1] > 0 ){
		temp = sum - nums[idx];
		ops[1] -= 1;
		go(nums, temp, idx+1);
		ops[1] +=1;
	}
	if(ops[2] > 0 ){
		temp = sum * nums[idx];
		ops[2] -= 1;
		go(nums,temp, idx+1);
		ops[2] += 1;
	}
	if(ops[3] > 0){
		temp = (long) (sum / nums[idx]);
		ops[3] -= 1;
		go(nums, temp, idx+1);
		ops[3] += 1;
	}
	return;

}


int main() {
	
	int n;
	//cin >> n;

#ifdef PRINT
	n = 6;
#endif

	vector<int> nums(n);
	/*
	for (int i=0; i<n; i++){
		cin >> nums[i];
	}
	*/

#ifdef PRINT
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	nums[3] = 4;
	nums[4] = 5;
	nums[5] = 6;
#endif
	/*
	for (int i=0; i<4; i++){
		cin >> ops[i];
	}
	*/
#ifdef PRINT
	ops[0] = 2;
	ops[1] = 1;
	ops[2] = 1;
	ops[3] = 1;

#endif

	go(nums, nums[0], 1);

	printf("%ld\n%ld\n",mm_pair.first, mm_pair.second);

	return 0;
}

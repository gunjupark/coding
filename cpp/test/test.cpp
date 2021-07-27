#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

int main() {

	vector<int> a(5,1);
	a.push_back(2);

	if(next_permutation(a.begin(), a.end()))
		printf("yes\n");
	else 
		printf("no\n");
		


	return 0;
}

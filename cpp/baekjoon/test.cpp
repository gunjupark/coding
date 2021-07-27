#include <vector>

using namespace std;

int main(){

	vector<int> a;

	a.push_back(12);
	a.push_back(5);
	a.push_back(8);
	a.push_back(1);

	vector<int> b = a;

	b[1] = 6;

	printf(" A \n");
	for (int aa : a){
		printf("%d \n",aa);

	}
	printf(" B \n");
	for(int bb : b){
		printf("%d \n", bb);
	}


	return 0;
}

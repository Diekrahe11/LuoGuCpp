#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	vector<int> arr;
	int x;
	while(cin >> x){
		arr.push_back(x);
	}
	
	int len = arr.size();
	long long sum = 0;
	for(int i = 0; i < len; ++i){
		sum += pow(2, len - 1) * arr[i]; 
	}
	
	cout << sum << endl;
	
	return 0;
}

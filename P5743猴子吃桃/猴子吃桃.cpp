#include <iostream>
using namespace std;

int lastDay(int num){
	return (num + 1) * 2;
}

int main() {
	int day;
	cin >> day;
	
	int sum = 1;
	for(int i = 0; i < day - 1; ++i){
		sum = lastDay(sum);
	}
	
	cout << sum << endl;
	
	return 0;
}

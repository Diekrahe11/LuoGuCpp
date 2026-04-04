#include <iostream>
using namespace std;

bool isPrime(int n){
	if(n < 2){
		return false;
	}
	
	if(n == 2){
		return true;
	}
	
	if(n % 2 == 0){
		return false;
	}
	
	for(int i = 3; i * i <= n; i += 2){
		if(n % i == 0){
			return false;
		}
	}
	
	return true;
}

int maxPrime(int n){
	int max = 0;
	for(int i = 2; i < n; ++i){
		if(n % i == 0){
			int temp = n % i;
			max = max > temp? max : temp;
		}
	}
	return max;
}

int main() {
	int n;
	cin >> n;
	cout << maxPrime(n) << endl;
	return 0;
}

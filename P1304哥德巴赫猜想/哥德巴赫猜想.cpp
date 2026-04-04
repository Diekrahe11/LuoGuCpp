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

int firstPrime(int n){
	for(int i = n - 2; i>= 0; --i){
		if(isPrime(i) && isPrime(n - i)){
			return n - i;
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	for(int i = 4; i <= n; i += 2){
		cout << i << "=";
		int first = firstPrime(i);
		int second = i - first;
		cout << first << "+" << second << endl;
	}
	
	return 0;
}

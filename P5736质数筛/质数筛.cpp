#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n){
	if(n <= 1){
		return false;
	}
	
	if(n == 2){
		return true;
	}
	
	if(n % 2 == 0){
		return false;
	}
	
	int limit = sqrt(n);
	for(int i = 3; i <= limit; ++i){
		if(n % i == 0) return false;
	}
	
	return true;
}

int main(){
	int n;
	cin >> n;
	
	int num;
	vector<int> prime;
	for(int i = 0; i < n; ++i){
		cin >> num;
		if(isPrime(num)){
			prime.push_back(num);
		}
	}
	
	for(int num : prime){
		cout << num << " ";
	}
	
	return 0;
}

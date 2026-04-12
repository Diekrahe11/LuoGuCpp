#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string num1, string num2){
	string res;
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	int carry = 0;
	
	while(i >= 0 || j >= 0 || carry > 0){
		int a = (i >= 0) ? (num1[i] - '0') : 0;
		int b = (j >= 0) ? (num2[j] - '0') : 0;
		
		int sum = a + b + carry;
		carry = sum / 10;
		res.push_back(sum % 10 + '0');
		
		i--;
		j--;
	}
	
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << add(a, b) << endl;
	return 0;
}

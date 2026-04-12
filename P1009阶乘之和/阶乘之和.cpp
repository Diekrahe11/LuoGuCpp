#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//´óÊıÏà³Ë
string multiply(string num1, string num2){
	if(num1 == "0" || num2 == "0") return "0";
	
	int m = num1.size(), n = num2.size();
	vector<int> res(m + n, 0);
	
	for(int i = m - 1; i >= 0; i--){
		for(int j = n - 1; j >= 0; j--){
			int num = (num1[i] - '0') * (num2[j] - '0');
			int p1 = i + j, p2 = i + j + 1;
			int sum = num + res[p2];
			
			res[p2] = sum % 10;
			res[p1] += sum / 10;
		}
	}
	
	string result;
	for(int num : res){
		if(!(result.empty() && num == 0)){
			result.push_back(num + '0');
		}
	}
	
	return result.empty()? "0" : result; 
}

string add(string num1, string num2){
	string res;
	int i = num1.size() - 1,  j = num2.size() - 1;
	int carry = 0;
	
	while(i >= 0 || j >= 0 || carry > 0){
		int a = (i >= 0)? (num1[i] - '0') : 0;
		int b = (j >= 0)? (num2[j] - '0') : 0;
		
		int sum = a + b + carry;
		carry = sum / 10;
		
		res.push_back(sum % 10 + '0');
		
		i--, j--;
	}
	
	reverse(res.begin(), res.end());
	return res;
}

string factorial(int num){
	if(num == 1) return "1";
	return multiply(to_string(num), factorial(num - 1));
}

int main() {
	int num;
	cin >> num;
	
	string result = "0";
	for(int i = 1; i <= num; ++i){
		result = add(result, factorial(i));
	}
	
	cout << result << endl;
	return 0;
}

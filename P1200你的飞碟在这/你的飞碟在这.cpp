#include <iostream>
using namespace std;

int toInt(string str){
	int res = 1;
	for(int i = 0; i < str.length(); ++i){
		res *= (int)str[i] - 64;
	}
	return res;
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	
	if((toInt(str1) % 47) == (toInt(str2) % 47)){
		cout << "GO" << endl;
	}else {
		cout << "STAY" << endl;
	}
	return 0;
}

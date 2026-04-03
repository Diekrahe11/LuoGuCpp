#include <iostream>
#include <cctype>
#include <map>
using namespace std;

int main() {
	string str;
	cin >> str;
	
	map<char, int> m;
	char temp;
	for(int i = 0; i < str.length(); ++i){
		if(isalpha(str[i])){
			temp = str[i];
		}
	}
	
	
	return 0;
}

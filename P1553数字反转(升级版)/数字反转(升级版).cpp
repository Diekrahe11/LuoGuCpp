#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//反转整数
string integer(string str){
	int len = str.length();
	
	if(len == 1){
		return str;
	}
	
	int nonZero = len - 1;
	for(int i = len - 1; i >= 0; --i){
		if(str[i] != '0'){
			nonZero = i;
			break;
		}
	}
	string res = str.substr(0, nonZero + 1);
	reverse(res.begin(), res.end());
	
	return res;
}

//小数部分除零
string removeZero(string decPart){
	bool zero = true;
	for(int i = 0; i < decPart.length(); ++i){
		if(decPart[i] != '0'){
			zero = false;
			break;
		}
	}
	
	if(zero){
		return "0";
	}
	
	reverse(decPart.begin(), decPart.end());
	for(int i = decPart.length() - 1; i >= 0; --i){
		if(decPart[i] != '0'){
			decPart = decPart.substr(0, i + 1);
			break;
		}
	}
	
	return decPart;
}

//反转小数
string decimals(string str){
	size_t symbol = str.find('.');
	
	string intPart = str.substr(0, symbol);
	string decPart = str.substr(symbol + 1);
	
	string res = "";
	res.append(integer(intPart));
	res.append(".");
	res.append(removeZero(decPart));
	
	return res;
}

//反转分数
string fraction(string str){
	int symbol = str.find('/');
	
	string numePart = str.substr(0, symbol);
	string denoPart = str.substr(symbol + 1);
	
	string res = integer(numePart) + "/" + integer(denoPart);
	return res;
}

//反转百分数
string percentage(string str){
	string res = str.substr(0, str.length() - 1);
	res = integer(res);
	res.append("%");
	
	return res;
}

int main(){
	string str;
	cin >> str;
	
	size_t pos = str.find('.');
	if(pos != string::npos){
		str = decimals(str);
		cout << str << endl;
		return 0;
	}
	
	pos = str.find('/');
	if(pos != string::npos){
		str = fraction(str);
		cout << str << endl;
		return 0;
	}
	
	pos = str.find('%');
	if(pos != string::npos){
		str = percentage(str);
		cout << str << endl;
		return 0;
	}
	
	str = integer(str);
	cout << str << endl;
	return 0;
}

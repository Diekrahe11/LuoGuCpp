#include <iostream>
#include <string>
using namespace std;

int count(string str, string s){
	int cnt = 0;
	
	size_t pos = 0;
	while((pos = str.find(s, pos)) != string::npos){
		cnt++;
		pos += 2;
	}
	
	return cnt;
}

bool changeK(string str, string s, int cnt){
	
	for(int i = 0; i < str.length() - 1; ++i){
		if(str[i] == 'V' && str[i + 1] != 'K'){
			char tem = str[i + 1];
			str[i + 1] = 'K';
			int temp = count(str, s);
			
			if(temp > cnt){
				return true;
			}
			str[i + 1] = tem;
		}
	}
	
	return false;
}

bool changeV(string str, string s, int cnt){
	
	for(int i = 1; i < str.length(); ++i){
		if(str[i] == 'K' && str[i - 1] != 'V'){
			char tem = str[i - 1];
			str[i - 1] = 'V';
			int temp = count(str, s);
			
			if(temp > cnt){
				return true;
			}
			str[i - 1] = tem;
		}
	}
	
	return false;
}

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	
	string s = "VK";
	
	int cnt = count(str, s);
	if(changeV(str, s, cnt) || changeK(str, s, cnt)){
		cnt++;
		cout << cnt << endl;
	}else{
		cout << cnt << endl;
	}
	
	return 0;
}

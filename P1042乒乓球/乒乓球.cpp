#include <iostream>
#include <string>
#include <vector>
using namespace std;

void calculateScore(const string& record, int target){
	int a = 0, b = 0;
	for(char c : record){
		if(c == 'W') a++;
		else if(c == 'L') b++;
	
		bool gameOver = false;
		if(a >= target && a - b >= 2){
			gameOver = true;
		}else if(b >= target && b - a >= 2){
			gameOver = true;
		}
	
		if(gameOver){
			cout << a << ":" << b << endl;
			a = 0;
			b = 0;
		}
	}
	
	cout << a << ":" << b << endl;
}

int main() {
	string line, record;
	bool endFlag = false;
	
	while(getline(cin, line)){
		for(char c : line){
			if(c == 'E'){
				endFlag = true;
				break;
			}
			record += c;
		}
		if(endFlag) break;
	}
	
	calculateScore(record, 11);
	cout << endl;
	calculateScore(record, 21);
}

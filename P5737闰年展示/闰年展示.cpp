#include <iostream>
#include <vector>
using namespace std;

bool isLeapyear(int year){
	if(year % 4 == 0 && year % 100 != 0){
		return true;
	}else if(year % 400 == 0){
		return true;
	}
	
	return false;
}

int main() {
	int first, last;
	cin >> first >> last;
	
	vector<int> leapYear;
	for(int i = first; i <= last; ++i){
		if(isLeapyear(i)){
			leapYear.push_back(i);
		}
	}
	
	cout << leapYear.size() << endl;
	for(int num : leapYear){
		cout << num << " ";
	}
	
	return 0;
}

#include <iostream>
using namespace std;

struct Student{
	int id;
	int study;
	int quality;
	
	bool comprehensive() const{
		return study * 0.7 + quality * 0.3 >= 80;
	}
	
	bool sum() const{
		return study + quality > 140;
	}
};

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		Student s;
		cin >> s.id >> s.study >> s.quality;
		
		if(s.comprehensive() && s.sum()){
			cout << "Excellent" << endl;
		}else{
			cout << "Not excellent" << endl;
		}
	}
	
	return 0;
}

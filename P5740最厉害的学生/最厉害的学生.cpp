#include <iostream>
#include <string>
using namespace std;

struct Student{
	string name;
	int chinese;
	int math;
	int english;
	
	int total() const{
		return chinese + math + english;
	}
};

int main() {
	int n;
	cin >> n;
	Student best;
	int maxTotal = -1;
	
	for(int i = 0; i < n; ++i){
		Student s;
		cin >> s.name >> s.chinese >> s.math >> s.english;
		
		if(s.total() > maxTotal){
			maxTotal = s.total();
			best = s;
		}
	}
	
	cout << best.name << " " << best.chinese << " "
		 << best.math << " " << best.english << endl;
}

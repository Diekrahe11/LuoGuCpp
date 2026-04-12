#include <iostream>
#include <string>
using namespace std;

struct Student{
	string name;
	int age;
	int score;
};

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		Student s;
		cin >> s.name >> s.age >> s.score;
		
		cout << s.name << " ";
		cout << s.age + 1 << " ";
		int newScore = s.score * 1.2;
		if(newScore > 600){
			newScore = 600;
		}
		cout << newScore << endl;
	}
	
	return 0;
}

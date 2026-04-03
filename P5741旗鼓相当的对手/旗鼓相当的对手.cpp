#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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

	vector<Student> st(n);
    for(int i = 0 ; i < n; ++i){
        cin >> st[i].name >> st[i].chinese >> st[i].math >> st[i].english;
    }
    
    for(int i = 0; i < n - 1; ++i){
		for(int j = i + 1; j < n; ++j){
			if(abs(st[i].total() - st[j].total()) <= 10){
				if(abs(st[i].chinese - st[j].chinese) <= 5 && 
				   abs(st[i].math - st[j].math) <= 5 &&
				   abs(st[i].english - st[j].english) <= 5){
				   		cout << st[i].name << " " << st[j].name << endl;
				   }
			}
		}
	}
    
    return 0;
}

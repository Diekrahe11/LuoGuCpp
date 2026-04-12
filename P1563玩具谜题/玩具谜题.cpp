#include <iostream>
#include <vector>
using namespace std;

struct Toy{
	int face;
	string name;
};

int main(){
	int num, order;
	cin >> num >> order;
	vector<Toy> arr(num);
	for(int i = 0; i < num; ++i){
		cin >> arr[i].face >> arr[i].name;
	}
	
	int cur = 0;
	for(int i = 0; i < order; ++i){
		int dir, amount;
		cin >> dir >> amount;
		
		if((dir + arr[cur].face) % 2 == 0){
			cur = (cur - amount % num + num) % num;
		}else {
			cur = (cur + amount % num) % num;
		}
	}
	
	cout << arr[cur].name << endl;
	
	return 0;
}

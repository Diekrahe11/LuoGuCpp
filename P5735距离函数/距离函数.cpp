#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	vector<vector<int>> arr(3);
	for(int i = 0; i < 3; ++i){
		vector<int> a(2);
		cin >> a[0];
		cin >> a[1];
		arr[i] = a;
	}
	
	double distance = 0;
	distance += sqrt(pow(arr[1][0] - arr[0][0], 2) + pow(arr[1][1] - arr[0][1], 2));
	distance += sqrt(pow(arr[2][0] - arr[0][0], 2) + pow(arr[2][1] - arr[0][1], 2));
	distance += sqrt(pow(arr[2][0] - arr[1][0], 2) + pow(arr[2][1] - arr[1][1], 2));
	
	cout << fixed << setprecision(2) << distance << endl;
	
	return 0;
}

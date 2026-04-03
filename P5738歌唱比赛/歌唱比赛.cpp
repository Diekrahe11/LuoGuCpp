#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	double max = 0;
	for(int i = 0; i < n; ++i){
		vector<int> score(m, 0);
		for(int j = 0; j < m; ++j){
			cin >> score[j];
		}
		
		sort(score.begin(), score.end());
		int sum = 0;
		double average = 0;
		for(int k = 1; k < m - 1; ++ k){
			sum += score[k];
		}
		
		average = sum * 1.0 / (m - 2);
		if(average > max){
			max = average;
		}
	}
	
	cout << fixed << setprecision(2) << max << endl;
	return 0;
}

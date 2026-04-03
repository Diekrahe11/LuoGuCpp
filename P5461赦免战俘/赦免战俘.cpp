#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void find(vector<vector<int>>& matrix){
	int index = matrix.size() / 2;
	
	for(int i = 0; i < index; ++i){
		for(int j = 0; j < index; ++j){
			matrix[i][j] = 0;
		}
	}
	
}

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> matrix(pow(2, n), vector<int>(pow(2, n), 1));
	
	return 0;
}

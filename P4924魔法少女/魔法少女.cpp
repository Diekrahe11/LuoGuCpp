#include <iostream>
#include <vector>
using namespace std;

void change(vector<vector<int>>& matrix, int x, int y, int r, int z){
	vector<vector<int>> temMatrix(2 * r + 1, vector<int>(2 * r + 1));
	
	if(z == 0){
		for(int i = x - r; i <= x + r; i++){
			for(int j = y - r; j <= y + r; j++){
				temMatrix[j - (y - r)][(x + r) - i] = matrix[i][j];
			}
		}
	}else{
		for(int i = x - r; i <= x + r; i++){
			for(int j = y - r; j <= y + r; j++){
				temMatrix[(y + r) - j][i - (x - r)] = matrix[i][j];
			}
		}
	}
	
	for(int i = 0; i < 2 * r + 1; ++i){
		for(int j = 0; j < 2 * r + 1; ++j){
			matrix[i + x - r][j + y - r] = temMatrix[i][j];
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	int num = 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			matrix[i][j] = num;
			num++;
		}
	}
	
	for(int i = 0; i < m; ++i){
		int x, y, r, z;
		cin >> x >> y >> r >> z;
		x--; y--;
		change(matrix, x, y, r, z);
	}
	
	for(vector<int> v : matrix){
		for(int i : v){
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}

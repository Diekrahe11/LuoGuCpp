#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> solution(vector<vector<char>> matrix, int row, int col){
	vector<vector<char>> res = matrix;
	
	//8个方向：上、下、左、右、四个对角线
	int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			if(res[i][j] == '?'){
				int temp = 0;
				
				//检查8个方向
				for(int k = 0; k < 8; ++k){
					int ni = i + dx[k];
					int nj = j + dy[k];
					
					//边界检查
					if(ni >= 0 && ni < row && nj >= 0 && nj < col){
						if(res[ni][nj] == '*'){
							temp++;
						}
					}
				}
				res[i][j] = temp + '0';
			}
		}
	}
	
	return res;
}

int main() {
	int row, col;
	cin >> row >> col;
	
	vector<vector<char>> matrix(row, vector<char>(col));
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			cin >> matrix[i][j];
		}
	}
	
	vector<vector<char>> res = solution(matrix, row, col);
	for(vector<char> ch : res){
		for(char c : ch){
			cout << c;
		}
		cout << endl;
	}
	
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    vector<vector<int>> matrix(n, vector<int>(n));
    matrix[0][n / 2] = 1;

    int lastRow = 0;
    int lastColumn = n / 2;
    for(int i = 2; i <= n * n; ++i){
        if(lastRow == 0 && lastColumn != n - 1){
            lastRow = n - 1;
            lastColumn = lastColumn + 1;
        }
        else if(lastRow != 0 && lastColumn == n - 1){
            lastRow = lastRow - 1;
            lastColumn = 0;
        }
        else if(lastRow == 0 && lastColumn == n - 1){
            lastRow = lastRow + 1;
        }
        else if(lastRow != 0 && lastColumn != n - 1){
            if(matrix[lastRow - 1][lastColumn + 1] == 0){
                lastRow = lastRow - 1;
                lastColumn = lastColumn + 1;
            }else {
                lastRow = lastRow + 1;
            }
        }
        matrix[lastRow][lastColumn] = i;
    }

    for(vector<int>arr : matrix){
        for(int x : arr){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

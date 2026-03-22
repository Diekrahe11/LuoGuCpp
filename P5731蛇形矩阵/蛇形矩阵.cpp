#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    int row = 0;
    int column = 0;
    int dir = 0;
    int num = 1;
    for(int i = n; i >= 1; --i){
        if(i == n){
            for(int j = 0; j < n; j++){
                arr[row][column] = num;
                num++;
                column++;
            }
            dir = 1;
            row++;
            column--;
            continue;
        }

        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < i; ++k){
                arr[row][column] = num;
                num++;
                if(dir == 0){
                    column++;
                }else if(dir == 1){
                    row++;
                }else if(dir == 2){
                    column--;
                }else {
                    row--;
                }
            }
            if(dir == 0){
                column--;
                row++;
            }else if(dir == 1){
                row--;
                column--;
            }else if(dir == 2){
                column++;
                row--;
            }else {
                row++;
                column++;
            }
            dir = (dir + 1) % 4;
        }
    }

    for(vector<int> a : arr){
        for(int i : a){
            cout << setw(2) << i << " ";
        }
        cout << endl;
        cout << " ";
    }
    return 0;
}

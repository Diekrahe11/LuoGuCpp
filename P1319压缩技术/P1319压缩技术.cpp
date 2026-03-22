#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int x;
    bool isZero = true;
    int row = 0;
    int column = 0;
    while(cin >> x){
        for(int i = 0; i < x; ++i){
            if(isZero){
                matrix[row][column] = 0;
                column++;
                if(column == n){
                    column = 0;
                    row++;
                }
            }else{
                matrix[row][column] = 1;
                column++;
                if(column == n){
                    column = 0;
                    row++;
                }
            }
        }
        isZero = !isZero;
    }

    for(vector<int> arr : matrix){
        for(int x : arr){
            cout << x;
        }
        cout << endl;
    }
    return 0;
}

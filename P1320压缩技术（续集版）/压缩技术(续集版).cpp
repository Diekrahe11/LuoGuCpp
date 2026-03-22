#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
    string line;
    vector<vector<int>> matrix;
    while(getline(cin, line)){
        int x;
        vector<int> arr;
        while(cin >> x){
            arr.push_back(x);
        }
        matrix.push_back(arr);
        arr.clear();
    }

    return 0;
}

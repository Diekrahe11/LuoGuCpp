#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }else if(n == 2){
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    cout << 1 << endl;
    cout << 1 << " " << 1 << endl;
    vector<int> arr(2, 1);
    for(int i = 0; i < n - 2; ++i){
        vector<int> newArr;
        newArr.push_back(1);
        for(int i = 0; i < arr.size() - 1; ++i){
            newArr.push_back(arr[i] + arr[i + 1]);
        }
        newArr.push_back(1);
        for(int j :newArr){
            cout << j << " ";
        }
        cout << endl;

        arr = newArr;
        newArr.clear();
    }

    return 0;
}

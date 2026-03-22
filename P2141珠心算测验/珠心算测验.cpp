#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i <n; ++i){
        cin >>arr[i];
    }

    set<int> count;
    sort(arr.begin(), arr.end());
    for(int i = 2; i < n; ++i){
        for(int j = 0; j < i - 1; ++j){
            for(int k = j + 1; k < i; ++k){
                if(arr[j] + arr[k] == arr[i]){
                    count.insert(arr[i]);
                }
            }
        }
    }
    cout << count.size() << endl;
    return 0;
}

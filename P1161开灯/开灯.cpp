#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

int getMax(const multimap<double, int>& arr){
    int max = 0;
    for(auto it = arr.begin(); it != arr.end(); ++it){
        int temp = floor(it->first) * (it->second);
        max = max > temp? max : temp;
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    multimap<double, int> arr;
    for(int i = 0; i < n; ++i){
        double db;
        int num;
        cin >> db >> num;
        arr.insert({db, num});
    }

    int len = getMax(arr);
    vector<bool> shift(len + 1, false);
    for(auto it = arr.begin(); it != arr.end(); ++it){
        for(int i = 1; i <= it->second; ++i){
            int temp = floor(it->first);
            shift[temp * i] = !shift[temp * i];
        }
    }

    for(int i = 0; i < len; ++i){
        if(shift[i]){
            cout << i << endl;
        }
    }
    return 0;
}

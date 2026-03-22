#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    int n;
    cin >> n;

    int num = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << setfill('0') << setw(2) << num;
            num++;
        }
        cout << endl;
    }
    cout << endl;

    num = 1;
    int amount = 1;
    for(int i = 0; i < n; ++i){
        for(int z = 0; z < 2 * (n - i - 1); ++z){
            cout << " ";
        }
        for(int j = 0; j < amount; ++j){
            cout << setw(2) << num;
            num++;
        }
        amount++;
        cout << endl;
    }
    return 0;
}

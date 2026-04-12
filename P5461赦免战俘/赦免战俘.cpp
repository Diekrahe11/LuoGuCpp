#include <iostream>
#include <vector>
using namespace std;

void pardon(vector<vector<int>>& a, int x, int y, int size) {
    if (size == 1) return;

    int half = size / 2;

    // 左上角赦免（置0）
    for (int i = x; i < x + half; ++i) {
        for (int j = y; j < y + half; ++j) {
            a[i][j] = 0;
        }
    }

    // 递归其他三个块
    pardon(a, x, y + half, half);         // 右上
    pardon(a, x + half, y, half);         // 左下
    pardon(a, x + half, y + half, half);  // 右下
}

int main() {
    int n;
    cin >> n;

    int size = 1 << n;
    vector<vector<int>> a(size, vector<int>(size, 1));

    pardon(a, 0, 0, size);

    for (auto& row : a) {
        for (int i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i != row.size() - 1) cout << " ";
        }
        cout << endl;
    }
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    vector<string> grid;
    int N = 0;

    // 1. 读取所有行，并确定 N
    while (getline(cin, line)) {
        if (line.empty()) continue;
        if (grid.empty()) {
            N = line.length();
        }
        grid.push_back(line);
    }

    if (N == 0) return 0;

    // 2. 输出第一个数 N
    cout << N;

    // 3. 开始游程编码
    // 我们将整个网格视为一个流，用一个指针 (row, col) 来遍历
    int row = 0, col = 0;

    // 我们需要统计的是交替的 0 和 1 的个数。
    // 我们从期望遇到 '0' 开始。
    bool expect_zero = true;
    int count = 0;

    while (row < grid.size()) {
        char current_char = grid[row][col];

        if (expect_zero) {
            if (current_char == '0') {
                count++;
            } else {
                // 遇到了 '1'，说明连续的 '0' 结束了
                cout << " " << count;
                count = 0; // 重置计数器，准备统计 '1'
                expect_zero = false; // 现在期望遇到 '1'

                // 重要：当前这个 '1' 是新序列的开始，所以要计入
                count++;
            }
        } else { // expect_one
            if (current_char == '1') {
                count++;
            } else {
                // 遇到了 '0'，说明连续的 '1' 结束了
                cout << " " << count;
                count = 0; // 重置计数器，准备统计 '0'
                expect_zero = true; // 现在期望遇到 '0'

                // 重要：当前这个 '0' 是新序列的开始，所以要计入
                count++;
            }
        }

        // 移动到下一个位置
        col++;
        if (col == N) {
            col = 0;
            row++;
        }
    }

    // 4. 输出最后一段的计数
    cout << " " << count << endl;

    return 0;
}

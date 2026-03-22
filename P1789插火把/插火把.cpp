#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 定义最大范围，根据题目 n <= 150，开稍大一点防止越界
const int MAXN = 160;
bool lit[MAXN][MAXN]; // false 表示黑暗，true 表示照亮

int main() {
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    // 初始化数组，全局变量默认为 false (0)
    // 如果使用局部变量，需要手动填充 false

    // 1. 处理火把
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        // 火把照亮范围：曼哈顿距离 |dx| + |dy| <= 2
        // 遍历可能的偏移量，dx 从 -2 到 2
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (abs(dx) + abs(dy) <= 2) {
                    int nx = x + dx;
                    int ny = y + dy;
                    // 边界检查
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                        lit[nx][ny] = true;
                    }
                }
            }
        }
    }

    // 2. 处理萤石
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        // 萤石照亮范围：5x5 正方形，即 dx, dy 都在 [-2, 2] 之间
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int nx = x + dx;
                int ny = y + dy;
                // 边界检查
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                    lit[nx][ny] = true;
                }
            }
        }
    }

    // 3. 统计未被照亮的格子
    int dark_count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!lit[i][j]) {
                dark_count++;
            }
        }
    }

    cout << dark_count << endl;

    return 0;
}

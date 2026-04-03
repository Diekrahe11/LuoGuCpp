#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> total(26, 0);
    string line;
    
    // 读取4行输入
    for(int i = 0; i < 4; ++i){
        getline(cin, line);
        for(char ch : line){
            if(ch >= 'A' && ch <= 'Z'){  // 只处理大写字母
                total[ch - 'A']++;
            }
        }
    }
    
    // 找到最大出现次数
    int maxCount = *max_element(total.begin(), total.end());
    
    // 如果没有任何字母，直接输出字母表后结束
    if(maxCount == 0){
        for(int i = 0; i < 26; ++i){
            cout << (char)('A' + i);
            if(i < 25) cout << " ";
        }
        return 0;
    }
    
    // 创建柱状图矩阵（maxCount 行，26 列）
    vector<vector<char>> matrix(maxCount, vector<char>(26, ' '));
    
    // 填充矩阵：从底部向上填充 '*'
    for(int col = 0; col < 26; ++col){
        int height = total[col];
        for(int row = maxCount - 1; row >= maxCount - height; --row){
            matrix[row][col] = '*';
        }
    }
    
    // 输出柱状图
    for(int row = 0; row < maxCount; ++row){
        for(int col = 0; col < 26; ++col){
            cout << matrix[row][col];
            if(col < 25) cout << ' ';  // 列之间加空格
        }
        cout << endl;
    }
    
    // 输出字母表
    for(int i = 0; i < 26; ++i){
        cout << (char)('A' + i);
        if(i < 25) cout << ' ';
    }
    
    return 0;
}

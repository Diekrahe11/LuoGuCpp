#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, str;
    cin >> s;
    cin.ignore();
    getline(cin, str);

    // 转小写
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    int count = 0;
    int firstIndex = -1;

    size_t pos = str.find(s);

    while (pos != string::npos) {
        // 判断是否是完整单词
        bool left_ok = (pos == 0 || str[pos - 1] == ' ');
        bool right_ok = (pos + s.size() == str.size() || str[pos + s.size()] == ' ');

        if (left_ok && right_ok) {
            count++;
            if (firstIndex == -1) {
                firstIndex = pos;
            }
        }

        pos = str.find(s, pos + 1); // 继续往后找
    }

    if (count == 0) {
        cout << -1 << endl;
    } else {
        cout << count << " " << firstIndex << endl;
    }

    return 0;
}

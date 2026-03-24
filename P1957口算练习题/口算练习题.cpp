#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void add(int m, int n){
    int temp = m + n;
    string str = to_string(m) + "+" + to_string(n) + "=" + to_string(temp);
    cout << str << endl;
    cout << str.size() << endl;
}

void sub(int m, int n){
    int temp = m - n;
    string str = to_string(m) + "-" + to_string(n) + "=" + to_string(temp);
    cout << str << endl;
    cout << str.size() << endl;
}

void mul(int m, int n){
    int temp = m * n;
    string str = to_string(m) + "*" + to_string(n) + "=" + to_string(temp);
    cout << str << endl;
    cout << str.size() << endl;
}

int main() {
    int i;
    cin >> i;
    cin.ignore();   //关键！忽略第一行后的换行符

    char type = ' ';
    for(int j = 0; j < i; ++j){
        string line;
        getline(cin, line);
        stringstream ss(line);

        char firstChar;
        ss >> firstChar;    //尝试读取第一个字符

        int m, n;

        //判断第一个字符是否为数字
        if(firstChar >= '0' && firstChar <= '9'){
            //情况1：格式是“2 3”（没有操作符）
            //需要把读取的字符放回去，重新读取两个整数
            ss.clear();
            ss.str(line);
            ss >> m >> n;
            //使用上一次的操作符
        }else {
            //情况2：格式是“a 2 3”（有操作符）
            type = firstChar;   //记录当前操作符
            ss >> m >> n;
        }

        if(type == 'a'){
            add(m, n);
        }else if(type == 'b'){
            sub(m, n);
        }else {
            mul(m, n);
        }
    }

    return 0;
}

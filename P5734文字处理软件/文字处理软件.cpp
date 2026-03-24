#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

void type1(string& str, string s){
    str += s;
    cout << str << endl;
}

void type2(string& str, int m, int n){
    str = str.substr(m, n);
    cout << str << endl;
}

void type3(string& str, int m, string s){
    str = str.insert(m, s);
    cout << str << endl;
}

void type4(string& str, string s){
    size_t pos = str.find(s);
    if(pos == string::npos){
        cout << -1 << endl;
    }else {
        cout << pos << endl;
    }
}

int main() {
    int q;
    cin >> q;
    string str;
    cin >> str;
    cin.ignore();

    for(int i = 0; i < q; ++i){
        string line;
        getline(cin, line);
        stringstream ss(line);

        int op;
        ss >> op;
        if(op == 1){
            string s;
            ss >> s;
            type1(str, s);
        }else if(op == 2){
            int m, n;
            ss >> m >> n;
            type2(str, m, n);
        }else if(op == 3){
            int m;
            string s;
            ss >> m >> s;
            type3(str, m, s);
        }else {
            string s;
            ss >> s;
            type4(str, s);
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> clockwise(vector<vector<char>> before, int n){
    vector<vector<char>> res(n, vector<char>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int row = j;
            int column = n - 1 - i;
            res[row][column] = before[i][j];
        }
    }
    return res;
}

vector<vector<char>> reflect(vector<vector<char>> before, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n / 2; ++j){
            int temp = before[i][j];
            before[i][j] = before[i][n - 1 - j];
            before[i][n - 1 - j] = temp;
        }
    }
    return before;
}

bool judge(vector<vector<char>> before, vector<vector<char>> later){
    int n = before.size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(before[i][j] != later[i][j]){
                return  false;
            }
        }
    }
    return true;
}

bool style1(vector<vector<char>> before, vector<vector<char>> later, int n){
    vector<vector<char>> res = clockwise(before, n);

    return judge(res, later);
}

bool style2(vector<vector<char>> before, vector<vector<char>> later, int n){
    vector<vector<char>> res = clockwise(before, n);
    res = clockwise(res, n);

    return judge(res, later);
}

bool style3(vector<vector<char>> before, vector<vector<char>> later, int n){
    vector<vector<char>> res = clockwise(before, n);
    res = clockwise(res, n);
    res = clockwise(res, n);

    return judge(res, later);
}

bool style4(vector<vector<char>> before, vector<vector<char>> later, int n){
    vector<vector<char>> res = reflect(before, n);

    return judge(res, later);
}

bool style5(vector<vector<char>> before, vector<vector<char>> later, int n){
    vector<vector<char>> ref = reflect(before, n);
    vector<vector<char>> res = clockwise(ref, n);
    if(judge(res, later)){
        return true;
    }
    res = clockwise(res, n);
    if(judge(res, later)){
        return true;
    }
    res = clockwise(res, n);
    if(judge(res, later)){
        return true;
    }

    return false;
}

bool style6(vector<vector<char>> before, vector<vector<char>> later, int n){
    return judge(before, later);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<char>> before(n, vector<char>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> before[i][j];
        }
    }
    vector<vector<char>> later(n, vector<char>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <n; ++j){
            cin >> later[i][j];
        }
    }

    if(style1(before, later, n)){
        cout << 1;
        return 0;
    }else if(style2(before, later, n)){
        cout << 2;
        return 0;
    }else if(style3(before, later, n)){
        cout << 3;
        return 0;
    }else if(style4(before, later, n)){
        cout << 4;
        return 0;
    }else if(style5(before, later, n)){
        cout << 5;
        return 0;
    }else if(style6(before, later, n)){
        cout << 6;
        return 0;
    }else{
        cout << 7;
        return 0;
    }

    return 0;
}

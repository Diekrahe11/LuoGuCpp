#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isPrime(int max, int min){
    int temp = max - min;
    if(temp == 2){
        return true;
    }else if(temp == 0 || temp == 1){
        return false;
    }

    for(int i = 2; i < temp; ++i){
        if(temp % i == 0){
            return false;
        }
    }

    return true;
}

int main() {
    string str;
    cin >> str;

    map<char, int> cnt;
    for(int i = 0; i < str.size(); ++i){
        auto it = cnt.find(str[i]);
        if(it != cnt.end()){
            cnt[str[i]]++;
        }else {
            cnt.insert({str[i], 1});
        }
    }

    int min = 100;
    int max = 0;
    for(const auto& pair : cnt){
        if(pair.second < min){
            min = pair.second;
        }
        if(pair.second > max){
            max = pair.second;
        }
    }

    if(isPrime(max, min)){
        cout << "Lucky Word" << endl;
        cout << max - min << endl;
    }else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }

    return 0;
}

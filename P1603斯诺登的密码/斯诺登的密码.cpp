#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string toInt(string str){
    // 转换为小写
    for(size_t i = 0; i < str.length(); ++i){
        str[i] = (char)tolower(str[i]);
    }
    
    // 数字单词到平方数后两位的映射
    if(str == "zero" || str == "ten"){
        return "00";
    }else if(str == "one" || str == "a" || str == "another" || str == "first"){
        return "01";
    }else if(str == "two" || str == "both" || str == "second"){
        return "04";
    }else if(str == "three" || str == "third"){
        return "09";
    }else if(str == "four"){
        return "16";
    }else if(str == "five"){
        return "25";
    }else if(str == "six"){
        return "36";
    }else if(str == "seven"){
        return "49";
    }else if(str == "eight"){
        return "64";
    }else if(str == "nine"){
        return "81";
    }else if(str == "eleven"){
        return "21";
    }else if(str == "twelve"){
        return "44";
    }else if(str == "thirteen"){
        return "69";
    }else if(str == "fourteen"){
        return "96";
    }else if(str == "fifteen"){
        return "25";
    }else if(str == "sixteen"){
        return "56";
    }else if(str == "seventeen"){
        return "89";
    }else if(str == "eighteen"){
        return "24";
    }else if(str == "nineteen"){
        return "61";
    }else if(str == "twenty"){
        return "00";
    }else {
        return "-1";
    }
}

// 返回排序后拼接的字符串
string getMinString(vector<string> num){
    if(num.empty()){
        return "0";
    }
    
    // 直接对字符串数组排序（字典序）
    sort(num.begin(), num.end());
    
    // 拼接结果
    string res = "";
    for(int i = 0; i < num.size(); ++i){
        res += num[i];
    }
    
    // 去掉前导零
    size_t pos = res.find_first_not_of('0');
    if(pos == string::npos){
        return "0";
    }
    
    return res.substr(pos);
}

int main() {
    string line;
    getline(cin, line);
    
    stringstream ss(line);
    vector<string> str(6);
    for(int i = 0; i < 6; ++i){
        ss >> str[i];
    }
    
    vector<string> num;
    for(int i = 0; i < 6; ++i){
        string temp = toInt(str[i]);
        if(temp != "-1"){
            num.push_back(temp);
        }
    }
    
    cout << getMinString(num) << endl;
    return 0;
}

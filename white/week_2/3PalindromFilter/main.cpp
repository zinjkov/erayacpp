//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

bool isPalindrom(string_view s){
    auto size = s.size();
    for(int i = 0; i < size / 2 + 1; i++) {
        if (s[i] != s[size - 1 - i]) {
            return false;
        }
    }
    return true;
}


vector<string> PalinromFilter(const vector<string> &strings, size_t min_size) {
    vector<string> result;
    for(auto &s : strings) {
        if (s.size() >= min_size && isPalindrom(s)) {
            result.push_back(s);
        }
    }
    return result;
}
vector<string> parse(string_view s) {
    vector<string> result;
    string_view delimiter = ", ";
    size_t pos = 0;
    std::string_view token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        s = s.substr(pos + delimiter.size(), s.size() - pos - delimiter.size());
        result.emplace_back(token.begin(), token.end());
    }
    result.emplace_back(s.begin(), s.end());
    return result;
}

vector<string> parse(string s) {
    vector<string> result;
    string delimiter = ", ";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        s = s.substr(pos + delimiter.size(), s.size() - pos - delimiter.size());
        result.emplace_back(token.begin(), token.end());
    }
    result.emplace_back(s.begin(), s.end());
    return result;
}


void printStrings(const vector<string> &strings) {
    bool isNotFirst = false;
    for(auto& s : strings) {
        if (!isNotFirst) {
            isNotFirst = true;
        } else {
            cout << ", ";
        }
        cout << s;
    }
}
int main() {
    string s = "abacaba, aba";
    int n = 5;

    auto strings = parse(s);
    auto palindroms = PalinromFilter(strings, n);
    printStrings(palindroms);
}
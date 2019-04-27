//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <string_view>

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

int main() {
    string s = "";
    cin >> s;
    cout << (isPalindrom(s) ? "true" : "false");
}
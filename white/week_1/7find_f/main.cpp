//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    string s;
    cin >> s;
    auto it = find(begin(s), end(s), 'f');
    if(it == s.end()) {
        cout << -2;
    } else {
        it = find(it + 1, end(s), 'f');
        if (it == s.end()) {
            cout << -1;
        } else {
            cout << distance(begin(s), it);
        }
    }

    return 0;
}
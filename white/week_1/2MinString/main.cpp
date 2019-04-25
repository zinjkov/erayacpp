//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>

using namespace std;


int main() {
    string a, b, c;
    std::cin >> a >> b >> c;

    if (a < b) {
        if (a < c) {
            cout << a;
        } else {
            cout << c;
        }
    } else if (b < c) {
        cout << b;
    } else {
        cout << c;
    }

    return 0;
}
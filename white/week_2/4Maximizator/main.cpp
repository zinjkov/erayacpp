//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

void UpdateIfGreater(int a, int &b) {
    if (a > b) {
        b = a;
    }
}

int main() {
    int a, b = 0;
    cin >> a >> b;
    UpdateIfGreater(a, b);
    cout << a << " " << b;
}
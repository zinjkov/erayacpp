//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    int x, y = 0;
    cin >> x >> y;
    while(x > 0 && y > 0) {
        if (x > y) {
            x = x % y;
        } else {
            y = y % x;
        }
    }
    cout << x + y;
    return 0;
}
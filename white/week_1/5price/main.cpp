//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    double n, a, b, x, y = 0;
    cin >> n >> a >> b >> x >> y;
    if (n > b) {
        cout << n - n * (y / 100.);
    } else if (n > a) {
        cout << n - n * (x / 100.) ;
    } else {
        cout << n;
    }
    return 0;
}
//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    if (a == 0) {
        cout << - c / b;
        return 0;
    }
    double D = b * b - 4 * a * c;

    if (D > 0) {
        cout << (-b + sqrt(D)) / (2 * a) << " " << (-b - sqrt(D)) / (2 * a);
    } else if (D == 0) {
        cout << (-b) / (2 * a);
    }


    return 0;
}
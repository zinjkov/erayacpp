//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    if (b == 0) cout << "Impossible";
    else cout << a / b;
    return 0;
}
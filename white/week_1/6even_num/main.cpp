//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    int  a, b = 0;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }
    return 0;
}
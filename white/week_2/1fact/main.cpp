//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>


using namespace std;
int Factorial(int n) {
    if (n <= 0) return 1;
    return n * Factorial(n - 1);
}
int main() {
    int n = 0;
    cin >> n;
    cout << Factorial(n);
}
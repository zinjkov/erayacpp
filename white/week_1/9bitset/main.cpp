//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    vector<int> v;
    int n = 0;
    cin >> n;
    while (n != 0) {
        v.push_back(n & 0x1);
        n >>= 1;
    }
    auto it = v.rbegin();
    while(it != v.rend()) {
        cout << *it;
        it++;
    }
    return 0;
}
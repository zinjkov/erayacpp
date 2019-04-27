//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), [](int a, int b) { return abs(a) < abs(b); });
    for(int x : v) {
        cout << x << " ";
    }

}
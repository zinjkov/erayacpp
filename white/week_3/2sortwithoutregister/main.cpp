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
    vector<string> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        string data;
        cin >> data;
        v.push_back(data);
    }
    sort(v.begin(), v.end(), [](string a, string b) {
        std::transform(a.begin(), a.end(), a.begin(), ::tolower);
        std::transform(b.begin(), b.end(), b.begin(), ::tolower);
        return (a) < (b); });
    for(string &x : v) {
        cout << x << " ";
    }

}
//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    for(int i = 0; i < v.size() / 2 + 1; i++) {
        swap(v[i], v[v.size() - 1 - i]);
    }
}

template <class T>
void printVector(const vector<T> &to) {
    for(auto &&t : to) {
        cout << t << " ";
    }
    cout <<"\n";
}

int main() {
    vector<int> v {1,2,3,4,5};
    cout << "before\n";
    printVector(v);
    Reverse(v);
    cout << "after\n";
    printVector(v);
}
//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

template <class T>
void printVector(const vector<T> &to) {
    for(auto &&t : to) {
        cout << t << " ";
    }
    cout <<"\n";
}
int main() {
    vector<int> temp;
    int n = 0;
    cin >> n;
    int av = 0;
    for(int i = 0; i < n; i++) {
        int t = 0;
        cin >> t;
        av += t;
        temp.push_back(t);
    }
    av /= n;
    vector<int> ind;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] > av) {
            ind.push_back(i);
        }
    }
    cout << ind.size() << "\n";
    printVector(ind);

}
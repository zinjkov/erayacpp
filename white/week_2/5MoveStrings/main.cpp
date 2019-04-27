//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

void MoveStrings(vector<string> &source, vector<string> &destination) {
    for(auto &&s : source) {
        destination.emplace_back(move(s));
    }
    source.clear();
}
int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> dest = {"z"};
    MoveStrings(source, dest);
    cout << "source: \n";
    for(auto& s : source) {
        cout << s << "\n";
    }
    cout << "dest: \n";
    for(auto& s : dest) {
        cout << s << "\n";
    }
}
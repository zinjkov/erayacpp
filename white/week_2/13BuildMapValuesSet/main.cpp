//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> valuesSet;
    for(auto &&item : m) {
        valuesSet.insert(item.second);
    }
    return valuesSet;
}

int main() {
    set<string> values = BuildMapValuesSet({
                                                   {1, "odd"},
                                                   {2, "even"},
                                                   {3, "odd"},
                                                   {4, "even"},
                                                   {5, "odd"}
                                           });

    for (const string& value : values) {
        cout << value << endl;
    }

}
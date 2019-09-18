//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <unordered_map>
#include <tuple>

using namespace std;

template <typename K, typename V>
V &GetRefStrict(map<K,V> &dict, K key) {
    auto it = dict.find(key);
    if (it != dict.end()){
        return it->second;
    } else {
        throw runtime_error("GetRefStrict: Key not found");
    }
}

int main() {
    map<int, string> m = {{0, "value"}};
    string &item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}

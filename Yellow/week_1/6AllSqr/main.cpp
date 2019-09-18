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

template<typename T>
T Sqr(T x);

template<typename T, typename V>
map<T, V> Sqr(map<T, V> x);
template<typename T, typename V>
pair<T,V> Sqr(const pair<T,V> &lhs);
template<typename T>
vector<T> Sqr(vector<T> x);


template<typename T>
T Sqr(T x) {
    return x * x;
}
template<typename T, typename V>
pair<T,V> Sqr(const pair<T,V> &lhs) {
    return {lhs.first * lhs.first, lhs.second * lhs.second};
}

template<typename T>
vector<T> Sqr(vector<T> x) {
    vector<T> tmp;
    for( auto &&el : x) {
        tmp.push_back(Sqr(el));
    }
    return tmp;
}

template<typename T, typename V>
map<T, V> Sqr(map<T, V> x) {
    map<T, V> tmp;
    for( auto &&el : x) {
        tmp[el.first] = Sqr(el.second);
    }
    return tmp;
}


int main() {
// Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    vector<map<int, int>> vv = {{ {1, 3}}, {{2, 3}}};
    cout << "vector of vector:";
    for (auto &&x : Sqr(vv)) {
        for(auto t : x)
        cout << ' ' << t.first << " " << t.second;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}

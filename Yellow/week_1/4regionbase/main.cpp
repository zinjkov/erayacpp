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

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

bool operator<(const Region &lhs, const Region &rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
            tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    map<Region, int> counters;
    int max_count = 0;
    for(auto &&region : regions) {
        max_count = max(max_count, ++counters[region]);
    }
    return max_count;
}

int main() {

    cout << FindMaxRepetitionCount({
                                   {
                                           "Moscow",
                                           "Russia",
                                           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                           89
                                   }, {
                                           "Russia",
                                           "Eurasia",
                                           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                           89
                                   }, {
                                           "Moscow",
                                           "Russia",
                                           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                           89
                                   }, {
                                           "Moscow",
                                           "Russia",
                                           {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                           89
                                   }, {
                                           "Russia",
                                           "Eurasia",
                                           {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                           89
                                   },
                           }) << endl;

    cout << FindMaxRepetitionCount({
               {
                       "Moscow",
                       "Russia",
                       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                       89
               }, {
                       "Russia",
                       "Eurasia",
                       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                       89
               }, {
                       "Moscow",
                       "Russia",
                       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
                       89
               }, {
                       "Moscow",
                       "Toulouse",
                       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                       89
               }, {
                       "Moscow",
                       "Russia",
                       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                       31
               },
       }) << endl;

    return 0;
}

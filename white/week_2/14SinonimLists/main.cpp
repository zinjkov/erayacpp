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
#include <utility>
using namespace std;



int to_int(string_view in) {
    stringstream stream({in.begin(), in.end()});
    int x = 0;
    stream >> x;
    return x;
}
vector<string_view> split(string_view s) {
    vector<string_view> result;
    string_view delimiter = " ";
    size_t pos = 0;
    std::string_view token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        s = s.substr(pos + delimiter.size(), s.size() - pos - delimiter.size());
        result.push_back(token);
    }
    result.emplace_back(s);
    return result;
}


void add(set<pair<string, string>> &synList,string_view word1, string_view word2) {
    synList.insert({string{word1}, string{word2}});
}

void count(set<pair<string, string>> &synList, string_view word) {
    int counter = 0;
    for (auto &&synonym : synList) {
        if (synonym.first == word || synonym.second == word) {
            counter++;
        }
    }
    cout << counter << "\n";
}

void check(set<pair<string, string>> &synList, string_view word1, string_view word2) {
    auto it = synList.find({string{word1}, string {word2}});
    if (it != synList.end()) {
        cout << "Yes\n";
    } else {
        it = synList.find({string{word2}, string {word1}});
        if (it != synList.end()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int process(const vector<string_view> &cmd, set<pair<string, string>> &synList) {

    if (cmd[0] == "ADD"){
        add(synList, cmd[1], cmd[2]);
        return 1;
    }

    if (cmd[0] == "COUNT"){
        count(synList, cmd[1]);
        return 1;
    }

    if (cmd[0] == "CHECK"){
        check(synList, cmd[1], cmd[2]);
        return 1;
    }

    return 0;
}
int main() {
    set<pair<string, string>> synonymSet;
    int command_count = 0;
    cin >> command_count;

    while(command_count) {
        string request;
        getline(cin, request);
        command_count -= process(split(request), synonymSet);
    }

}
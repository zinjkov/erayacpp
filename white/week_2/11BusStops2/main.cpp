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


int process(const vector<string_view> &cmd,  map<vector<string>, int> &buses) {

    if (cmd.size() > 1) {

        auto it = buses.find({cmd.begin() + 1, cmd.end()});
        if (it != buses.end()) {
            cout << "Already exists for " << it->second << "\n";
        } else {
            int number = 1 + buses.size();
            buses[{cmd.begin() + 1, cmd.end()}] = number;
            cout << "New bus " << number << "\n";
        }
        return 1;
    }

    return 0;
}
int main() {
    map<vector<string>, int> buses;
    int command_count = 0;
    cin >> command_count;

    while(command_count) {
        string request;
        getline(cin, request);
        command_count -= process(split(request), buses);
    }

}
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

template<class It>
void new_bus(map<string, vector<string>> &buses, string_view bus, It ItBeginStops, It ItEndStops) {
    auto it = buses.insert({{bus.begin(), bus.end()}, vector<string>()});
    while(ItBeginStops != ItEndStops) {
        it.first->second.push_back({ItBeginStops->begin(), ItBeginStops->end()});
        ItBeginStops++;
    }
}

void buses_for_stop(const map<string, vector<string>> &buses, string_view stop, string_view no_placeholder = "No stop", string_view ignore = "") {
    bool noStops = true;
    vector<string> bus_tmp;
    for(auto &&bus : buses) {
        if (bus.first == ignore) continue;
        auto it = find(bus.second.begin(), bus.second.end(), string{stop.begin(), stop.end()});
        if (it != bus.second.end()) {
            cout << bus.first << " ";
            noStops = false;
        }
    }
    if (noStops) {
        cout << no_placeholder;
    }
    cout << "\n";
}

void stops_for_bus(const map<string, vector<string>> &buses, string_view bus) {
    if (buses.empty()) { cout << "No bus\n"; return; }
    vector<string_view> stops_tmp;
    auto it = buses.find({bus.begin(), bus.end()});
    if (it != buses.end()) {
        for(auto &&stop : it->second) {
            stops_tmp.push_back(stop);
        }
    } else {
        cout << "No stop";
    }
    for(auto &&el : stops_tmp) {
        cout << "Stop " << el << ": ";
        buses_for_stop(buses, el, "no interchange", bus);
    }

    cout << "\n";
}

void all_buses(const map<string, vector<string>> &buses) {
    if (buses.empty()) cout << "No Buses\n";
    for(auto &&bus : buses) {
        cout << "Bus "<<  bus.first << ": ";
        for(auto &&stop : bus.second) {
            cout << stop << " ";
        }
        cout << "\n";
    }

}

int process(const vector<string_view> &cmd, map<string, vector<string>> &buses) {
    if (cmd[0] == "NEW_BUS") {
        new_bus(buses, cmd[1], cmd.begin()+3, cmd.end());
        return 1;
    }
    if (cmd[0] == "BUSES_FOR_STOP") {
        buses_for_stop(buses, cmd[1]);
        return 1;
    }
    if (cmd[0] == "STOPS_FOR_BUS") {
        stops_for_bus(buses, cmd[1]);
        return 1;
    }
    if (cmd[0] == "ALL_BUSES") {
        all_buses(buses);
        return 1;
    }


    return 0;
}
int main() {
    map<string, vector<string>> buses;
    int command_count = 0;
    cin >> command_count;

    while(command_count) {
        string request;
        getline(cin, request);
        command_count -= process(split(request), buses);
    }

}
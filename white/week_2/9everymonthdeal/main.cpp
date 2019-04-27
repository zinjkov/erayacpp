//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

const vector<int> days_in_month = {31, 28, 31, 30 ,31, 31, 30 ,31, 30, 31, 30, 31};


int day_inmonth(int month) {
    return days_in_month[month];
}
struct Dairy {
    vector<vector<string>> deal;
    int current_month;
    Dairy(): current_month(0) {
        deal.resize(day_inmonth(current_month));
    }
};

int next_month(int current) {
    return current + 1 % 12;
}


void Next(Dairy &dairy) {
    int current_days = day_inmonth(dairy.current_month);
    int next_days = day_inmonth(next_month(dairy.current_month));
    if (current_days > next_days) {
        for(int i = next_days - 1; i < current_days; i++) {
            dairy.deal[next_days - 1].insert(dairy.deal[next_days-1].end(), dairy.deal[i].begin(), dairy.deal[i].end());
        }
    }
    dairy.deal.resize(next_days);
    dairy.current_month = next_month(dairy.current_month);
}
void Add(Dairy &dairy, int day, string_view deal) {
    dairy.deal[day - 1].push_back({ deal.begin(), deal.end() });
}
void Dump(Dairy &dairy, int day) {
    cout << dairy.deal[day-1].size() << " ";
    for(auto &deal_in_day : dairy.deal[day - 1]) {
        cout << deal_in_day << " ";
    }
    cout << "\n";
}


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

int parse(vector<string_view> cmd, Dairy &dairy) {
    if (cmd.empty()) { cout << "inv cmd\n"; return 0;}

    if (cmd[0] == "ADD") {
        Add(dairy, to_int(cmd[1]), cmd[2]);
        return 1;
    }
    if (cmd[0] == "DUMP") {
        Dump(dairy, to_int(cmd[1]));
        return 1;
    }
    if (cmd[0] == "NEXT"){
        Next(dairy);
        return 1;
    }
    return 0;
}
int main() {
    Dairy dairy;
    int count_cmd = 0;
    cin >> count_cmd;
    while(count_cmd) {
        string cmd;
        getline(cin, cmd);
        count_cmd -= parse(split(cmd), dairy);
    }

}
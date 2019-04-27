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

//WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
//QUIET i: пометить i-го человека как успокоившегося;
//COME k: добавить k спокойных человек в конец очереди;
//COME -k: убрать k человек из конца очереди;
//WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
template <class T>
void printVector(const vector<T> &to) {
    for(auto &&t : to) {
        cout << t << " ";
    }
    cout <<"\n";
}

void Worry(vector<bool> &humans, int i) {
    humans[i] = true;
}

void Quiet(vector<bool> &humans, int i) {
    humans[i] = false;
}

void Come(vector<bool> &humans, int k) {
    if (k > 0) {
        humans.insert(humans.end(), k, false);
    } else {
        humans.erase(humans.end() - abs(k), humans.end());
    }
}

int worry_count(vector<bool> &humans) {
    return count(begin(humans), end(humans), true);
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

void parse(vector<string_view> cmd, vector<bool> &humans) {
    if (cmd.empty()) { cout << "inv cmd\n"; return ;}

    if (cmd[0] == "WORRY") {
        Worry(humans, to_int(cmd[1]));
    }
    if (cmd[0] == "QUIET") {
        Quiet(humans, to_int(cmd[1]));
    }
    if (cmd[0] == "COME"){
        Come(humans, to_int(cmd[1]));
    }
    if (cmd[0] == "WORRY_COUNT"){
        cout << worry_count(humans) << "\n";
    }

}

int main() {
    vector<bool> humans = {};
    int q = 0;
    cin >> q;
    string s;
    getline(cin, s);
    for(int i = 0; i < q; i++){
        string cmd;
        getline(cin, cmd);
        parse(split(cmd), humans);
    }
}
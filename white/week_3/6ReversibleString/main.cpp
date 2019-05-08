#include <utility>

//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

class ReversibleString {
public:
    ReversibleString() = default;
    explicit ReversibleString(string data) : m_data(std::move(data)) {}
    string ToString() const {
        return m_data;
    }
    void Reverse() {
        reverse(begin(m_data), end(m_data));
    }
private:
    string m_data;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}

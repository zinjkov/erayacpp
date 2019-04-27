//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        m_strings.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(m_strings.begin(), m_strings.end());
        return m_strings;
    }
private:
    vector<string> m_strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}

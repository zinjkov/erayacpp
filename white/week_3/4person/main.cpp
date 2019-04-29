//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;


template <class It, class T>
It find_less_then(It first, It last, T&& value) {
    It result = last;
    while(first != last) {
        if (first->first > value) {
            break;
        }
        result = first;
        first++;
    }
    return result;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        m_first[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        m_last[year] = last_name;
    }
    string GetFullName(int year) {

        auto it = find_less_then(m_first.begin(), m_first.end(), year);
        auto it_l = find_less_then(m_last.begin(), m_last.end(), year);

        if (it == m_first.end() && it_l == m_last.end()) {
            return "Incognito";
        }
        if (it != m_first.end() && it_l == m_last.end()) {
            return it->second + " with unknown last name";
        }
        if (it == m_first.end() && it_l != m_last.end()) {
            return it_l->second + " with unknown first name";
        }

        return it->second + " " + it_l->second;
    }
private:

    map<int, string> m_first;
    map<int, string> m_last;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

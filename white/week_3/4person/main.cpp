//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        m_first[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        m_last[year] = last_name;
    }
    string GetFullName(int year) {

        auto it = m_first.lower_bound(year);
        auto it_l = m_last.lower_bound(year);

        if(it == m_first.begin() && it->first > year) {
            it = m_first.end();
        } else {
            it--;
        }
        if(it_l == m_last.begin() && it_l->first > year) {
            it_l = m_last.end();
        } else {
            it_l--;
        }
        if (it == m_first.end() && it_l == m_last.end()) {
            return "Incognito";
        }
//        cout << year << " " << it->first << " " << it_l->first <<"\n";
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

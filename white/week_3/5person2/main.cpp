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

template <class It, class T>
vector<string> find_all_less_then(It first, It last, T&& value) {
    vector<string> result;
    auto it = find_less_then(first, last, value);

    if (it != last) {
        it++;
        while (first != it) {
            result.push_back(first->second);
            first++;
        }

    }
    return result;
}


string person_list_to_string(vector<string> history) {
    if (history.empty()) return "";

    auto uniq_it = unique(begin(history), end(history));
    history.erase(uniq_it, end(history));

    auto first = history.rbegin();
    string result = *first;
    first++;
    if (first == history.rend()) {
        return result;
    }
    result += " (";
    while(first != history.rend()) {
        result += *first + ", ";
        first++;
    }
    result.erase(result.end() - 2, result.end());
    result += ")";
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

    string GetFullNameWithHistory(int year) {
        auto first_history = find_all_less_then(m_first.begin(), m_first.end(), year);
        auto last_history = find_all_less_then(m_last.begin(), m_last.end(), year);

        if (first_history.empty() && last_history.empty()) {
            return "Incognito";
        }

        if (!first_history.empty() && last_history.empty()) {
            return person_list_to_string(first_history) + " with unknown last name";
        }

        if (first_history.empty() && !last_history.empty()) {
            return  person_list_to_string(last_history) + " with unknown first name";
        }

        return person_list_to_string(first_history) + " " + person_list_to_string(last_history);
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
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}

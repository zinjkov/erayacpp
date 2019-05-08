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
    Person(const string &first_name, const string &last_name, int year) {
        m_first[year] = first_name;
        m_last[year] = last_name;
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (year >= m_first.begin()->first) {
            m_first[year] = first_name;
        }
    }

    void ChangeLastName(int year, const string& last_name) {
        if (year >= m_last.begin()->first) {
            m_last[year] = last_name;
        }
    }

    string GetFullName(int year) {

        if (m_last.begin()->first > year) {
            return "No person";
        }

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
        if (m_last.begin()->first > year) {
            return "No person";
        }
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
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}

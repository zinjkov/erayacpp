#include <iostream>
#include <exception>
#include <string>
#include <iomanip>
#include <map>
#include <set>
using namespace std;


struct Date {
    Date(int year, int month, int day) {
        if (month > 12 || month < 0) {
            throw runtime_error("month error");
        }
        if (month > 31 || month < 0) {
            throw runtime_error("day error");
        }

        this->month = month;
        this->year = year;
        this->day = day;
    }
    Date() = default;

    int year = 0;
    int month = 0;
    int day = 0;

    string toString() {
        return std::to_string(day) + "-" + std::to_string(month) + "-" + std::to_string(year);
    }
};
bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.year < rhs.year) {
        return true;
    } else if (lhs.month < rhs.month) {
        return true;
    } else if (lhs.day < rhs.day) {
        return  true;
    }
    return false;
}

ostream &operator<< (ostream &os, Date date) {
    os << setfill('0');
    os << setw(2) << date.year << "-";
    os << setw(2) << date.month << "-";
    os << setw(4) << date.day;
    return os;
}

istream &operator>> (istream &is, Date &date) {
    is >> date.year;
    is.ignore(1);
    is >> date.month;
    is.ignore(1);
    is >> date.day;
    return is;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event);
    bool DeleteEvent(const Date& date, const string& event) {
        auto it = m_data.find(date);
        auto setit = it->second.find(event);
        if (setit != it->second.end()) {
            it->second.erase(setit);
            cout << "Deleted successfully";
        } else {
            cout << "Event not found";
        }
    }

    int  DeleteDate(const Date& date) {
        auto it = m_data.find(date);
        if (it != m_data.end()) {
            m_data.erase(it);
            cout << "Deleted successfully";
        }else {
            cout << "Date not found";
        }
    }

    int Find(const Date& date) const {
        auto it = m_data.find(date);
        if (it != m_data.end()) {
            for (const auto &ev : it->second) {
                cout << ev << ", ";
            }
        } else {
            cout << "Event not found";
        }
    }

    void Print() const {
        for (const auto &date : m_data) {
            cout << date.first << ": ";
            for(const auto &ev : date.second) {
                cout << ev << ", ";
            }
        }
    }
private:
    map<Date, set<string>> m_data;
};

void Database::AddEvent(const Date &date, const string &event) {
    auto it = m_data.find(date);
    if (it == m_data.end()) {
        m_data[date] = {event};
    } else {
        it->second.insert(event);
    }
}


pair<string_view, string_view> split_type(string_view cmd) {
    auto it = cmd.find(' ');
    return {cmd.substr(0, it), cmd.substr(it + 1)};
}

pair<Date, string_view> split_date(string_view cmd) {
    auto it = cmd.find(' ');
    stringstream os(string{cmd.begin(), cmd.end()});
    Date d;
    os >> d;
    if (it == std::string::npos) {
        return {d, ""};
    }
    return {d, cmd.substr(it + 1)};
}

Date  date_from_string(string_view cmd) {
    stringstream os(string{cmd.begin(), cmd.end()});
    Date d;
    os >> d;
    return d;
}

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        if (!command.empty()) {
            try {
                auto[type, cmd] = split_type(command);
                if (type == "Add") {
                    auto[date, ev] = split_date(cmd);
                    db.AddEvent(date, {ev.begin(), ev.end()});
                }
                if (type == "Del") {
                    auto[date, ev] = split_date(cmd);
                    if (ev.empty()) {
                        db.DeleteDate(date);
                    } else {
                        db.DeleteEvent(date, string{ev.begin(), ev.end()});
                    }
                }
                if (type == "Print") {
                    db.Print();
                }
                if (type == "Find") {
                    auto date = date_from_string(cmd);
                    cout << date <<"  ";
                    db.Find(date);
                }
                cout << endl;
            } catch (exception &ex) {
                cerr << ex.what() << endl;
            }
        }
    }

    return 0;
}
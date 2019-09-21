#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    // Реализуйте эту функцию
    string operation_code;
    is >> operation_code;
    if (operation_code == "NEW_BUS") {
        q.type = QueryType::NewBus;
        string bus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (int i = 0; i < stop_count; i++) {
            string stop;
            is >> stop;
            q.stops[i] = stop;
        }
    } else if (operation_code == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (operation_code == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        cin >> q.bus;
    } else if (operation_code == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    // Наполните полями эту структуру
    string stop;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (!r.stop.empty()) {
        os << "Stop " << r.stop << ":";
        for (auto &&bus : r.buses) {
            os << " " <<  bus;
        }
    } else {
        os << "No stop";
    }
    return os;
}

struct StopsForBusResponse {
    // Наполните полями эту структуру
    string bus;
    vector<string> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (!r.bus.empty()) {
        os << "Bus " << r.bus << ":";
        for(auto &&stop : r.stops) {
            os << " " << stop;
        }
    }else {
        os << "No bus";
    }
    return os;
}

struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> all_busses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (!r.all_busses.empty()) {
        for (auto && bus : r.all_busses) {
            os << "Bus " <<  bus.first << ":";
            for (auto &&stop : bus.second) {
                os << " " << stop;
            }
            os << "\n";
        }
    } else {
        os << "No buses";
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        // Реализуйте этот метод
        m_bus_to_stop.emplace(bus, stops);
        for (auto &&stop : stops) {
            m_stop_to_bus[stop].emplace_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        // Реализуйте этот метод
        BusesForStopResponse buses{};
        try {
            buses.buses = m_stop_to_bus.at(stop);
            buses.stop = stop;
        } catch (...) {}
        return buses;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse stops = {};
        try {
            stops.stops = m_bus_to_stop.at(bus);
            stops.bus = bus;

        } catch (...) {}
        return stops;
    }

    AllBusesResponse GetAllBuses() const {
        return {m_bus_to_stop};
    }

private:
    map<string, vector<string>> m_bus_to_stop;
    map<string, vector<string>> m_stop_to_bus;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}

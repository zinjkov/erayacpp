//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    vector<size_t> days;
    size_t days_count = 0;
    cin >> days_count;
    days.resize(days_count);
    size_t av = 0;
    for(int i = 0; i < days_count; i++) {
        cin >> days[i];
        av += days[i];
    }

    av /= days_count;
    vector<size_t> more_av;
    for(int i = 0; i < days_count; i++) {
        if (days[i] > av) {
            more_av.push_back(days[i]);
        }
    }

    cout << more_av.size();
    for(auto &el : more_av) {
        cout << " " << el;
    }
    return 0;
}
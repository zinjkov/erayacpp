//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
using namespace std;



int main() {
    set<string> unique_strings;
    int command_count = 0;
    cin >> command_count;

    for(int i = 0; i < command_count; i++) {
        string request;
        cin >> request;
        unique_strings.insert(request);
    }
    cout << unique_strings.size();

}
//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;


struct student {
    string name;
    int day, month, year = 0;
};



int main() {
    int n = 0;
    cin >> n;
    vector<student> students;
    for(int i = 0; i < n; i++) {
        student s;
        string fam;
        cin >> s.name >> fam;
        s.name += " " + fam;
        cin >> s.day >> s.month >> s.year;
        students.push_back(s);
    }
    int m = 0;
    cin >> m;

    while (m--) {
        string cmd;
        cin >> cmd;
        int k = 0;
        cin >> k;
        if (cmd[0] == 'd') {
            cout << students[k-1].day << "." << students[k-1].month << "." << students[k-1].year << endl;
        } else if (cmd[0] == 'n') {
            cout << students[k-1].name << endl;
        } else {
            cout << "bad request" << endl;
        }
    }


}
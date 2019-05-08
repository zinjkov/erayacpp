//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

void createFile() {
    ofstream output("input.txt");
    for(auto &&str : {"Keep calm\n", "and\n", "learn C++\n"}) {
        output << str;
    }
}


int main() {
    createFile();
    {
        ifstream input("input.txt");
        if (input) {
            string data;
            while (getline(input, data)) {
                cout << data << endl;
            }
        }
    }

    {
        ifstream input("input.txt");
        ofstream output("output.txt");
        if (input && output) {
            string data;
            while (getline(input, data)) {
                output << data << endl;
            }
        }
    }


}
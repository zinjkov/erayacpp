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

void createFile() {
    ofstream output("input.txt");
    for(double str : {5.0, 0.34567, 10.4, 3.33353, 3.333, 3.3}) {
        output << str << endl;
    }
}


int main() {
//    createFile();
    {
        ifstream input("input.txt");
        if (input) {
            double data;
            cout << std::setprecision (3) << std::fixed;
            while (!input.eof()) {
                input >> data;
                cout << std::setprecision (3) << std::fixed  << data << endl;
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
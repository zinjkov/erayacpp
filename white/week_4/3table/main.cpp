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



int main() {
    int n, m = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int data = 0;
            cin >> data;
            cout << setw(10) << data << " ";
        }
        cout << endl;
    }

}
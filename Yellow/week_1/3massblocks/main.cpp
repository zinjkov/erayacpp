//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    int N = 0;
    int Ro = 0;

    cin >> N;
    cin >> Ro;

    string line;
    size_t total = 0;
    for(int i = 0; i < N ; i++){
        int H, W, D = 0;
        cin >> H  >> W >> D;

        total += H * W* D * Ro;
    }

    cout << total;
    return 0;
}
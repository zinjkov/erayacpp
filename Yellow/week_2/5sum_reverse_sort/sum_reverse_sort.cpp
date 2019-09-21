//
// Created by zinjk on 22.09.2019.
//

#include "sum_reverse_sort.h"
#include <algorithm>
int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    std::reverse(begin(s), end(s));
    return s;
}

void Sort(vector<int> &nums) {
    std::sort(begin(nums), end(nums));
}

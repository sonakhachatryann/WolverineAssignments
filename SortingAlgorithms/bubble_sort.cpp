#include "bubble_sort.h"
#include <utility>
#include <iostream>

void bubble_sort(std::vector<int>& vec) {
    bool b = true;
    for (int i = 0; i < vec.size() - 1; ++i) {
        b = true;
        for (int j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                b = false;
            }
        }
        if (b) {
            return;
        }
    }
}

void bubble_sort(std::forward_list<int>& list) {
    if (list.empty()) {
        return;
    }
    bool swapped = true;
    while(swapped) {
        swapped = false;
        auto prev = list.begin();
        auto cur = prev; ++cur;
        while(cur != list.end()) {
            if (*cur < *prev) {
                std::swap(*prev, *cur);
                swapped = true;
            }
            ++prev; ++cur;
        }
    }
}
#include "insertion_sort.h"
#include <utility>
#include <iostream>

void insertion_sort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j] > key) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion_sort(std::forward_list<int>& list) {
    if (list.empty()) {
        return;
    }
    auto it1 = list.begin();
    auto it1_prev = it1;
    ++it1;
    bool check = false;
    for (; it1 != list.end(); ++it1) {
        check = false;
        auto prev = list.before_begin();
        for (auto it2 = list.begin(); it2 != it1; ++it2) {
            if (*it1 < *it2) {
                check = true;
                list.insert_after(prev, *it1);
                list.erase_after(it1_prev);
                it1 = it1_prev;
                break;
            }
            ++prev;
        }
        if (!check) {
            ++it1_prev;
        }
    }
}

void insertion_recursive(std::vector<int>& arr, int size) {
    if (size <= 1) {
        return;
    }
    insertion_recursive(arr, size - 1);
    int last = arr[size - 1];
    int j = size - 2;
    while (j >= 0) {
        if (arr[j] > last) {
            std::swap(arr[j], arr[j + 1]);
        }
        --j;
    }
}
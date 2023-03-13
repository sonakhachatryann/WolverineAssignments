#include "selection_sort.h"
#include <utility>

void selection_sort(std::vector<int>& arr) {
    int min_index = 0;
    for (int i = 0; i < arr.size() - 1; ++i) {
        min_index = i;
        for (int j = i; j < arr.size(); ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(arr[min_index], arr[i]);
        }
    }
}

int min_index_recursive(const std::vector<int>& arr, int index) {
    if (index == arr.size() - 1) {
        return arr.size() - 1;
    }
    int k = min_index_recursive(arr, index + 1);
    return arr[index] < arr[k] ? index : k;
}

void selection_recursive(std::vector<int>& arr, int index) {
    if (index == arr.size()) {
        return;
    }
    int min_index = min_index_recursive(arr, index);
    if (min_index != index) {
        std::swap(arr[min_index], arr[index]);
    }
    selection_recursive(arr, index + 1);
}

void selection_sort(std::forward_list<int>& list) {
    if (list.empty()) {
        return;
    }
    for (auto it1 = list.begin(); it1 != list.end(); ++it1) {
        auto min = it1; 
        for (auto it2 = it1; it2 != list.end(); ++it2) {
            if (*it2 < *min) {
                std::swap(*it1, *it2);
            }
        }
    }
}
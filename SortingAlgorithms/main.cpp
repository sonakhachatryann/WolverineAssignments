#include <iostream>
#include <utility>
#include <vector>
#include <forward_list>

void bubble_sort(std::vector<int>&);
void bubble_sort(std::forward_list<int>&);
void selection_sort(std::vector<int>&);
int min_index_recursive(const std::vector<int>&, int);
void selection_recursive(std::vector<int>&, int);
void selection_sort(std::forward_list<int>&);
void insertion_sort(std::vector<int>&);
void insertion_sort(std::forward_list<int>&);
void insertion_recursive(std::vector<int>&, int);

int main() {

    std::forward_list<int> lst = {4, 6, 2, -7, 9, 1, 3};
    insertion_sort(lst);
    for (auto& it : lst) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> vec = {5, 8, -10, -7, 9, 14, 38};
    insertion_recursive(vec, vec.size());
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

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
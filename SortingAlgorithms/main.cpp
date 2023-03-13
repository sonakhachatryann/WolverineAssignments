#include <iostream>

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"

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
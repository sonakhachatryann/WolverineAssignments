#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>
#include <forward_list>

void insertion_sort(std::vector<int>&);
void insertion_recursive(std::vector<int>&, int);
void insertion_sort(std::forward_list<int>&);

#endif //INSERTION_SORT_H
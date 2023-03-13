#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <vector>
#include <forward_list>

void selection_sort(std::vector<int>&);
void selection_recursive(std::vector<int>&, int = 0);
int min_index_recursive(const std::vector<int>&, int);
void selection_sort(std::forward_list<int>&);

#endif
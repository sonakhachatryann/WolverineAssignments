#include <vector>

//137. Single Number II
//time complexity O(32*n) = O(n)
//space complexity O(1)
int singleNumber(std::vector<int>& nums) {
    int size_of_int = sizeof(int) * 8;
    int tmp = size_of_int;
    int result = 0;
    unsigned int shift = 1;
    int j = 0;
    while (tmp) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & shift) {
                ++count;
            }
        }
        if (count % 3 == 1) {
            result |= (1 << j);
        }
        ++j;
        shift <<= 1;
        --tmp;
    }
    return result;
}
#include <vector>

//260. Single Number III
//time complexity O(n)
//space complexity O(1)
std::vector<int> _singleNumber(std::vector<int>& nums) {
    unsigned int tmp = 0;
    for (int i = 0; i < nums.size(); ++i) {
        tmp ^= nums[i];
    }
    tmp &= -tmp;
    std::vector<int> result = {0, 0};
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] & tmp) {
            result[0] ^= nums[i];
        }
        else {
            result[1] ^= nums[i];
        }
    }
    return result;
}
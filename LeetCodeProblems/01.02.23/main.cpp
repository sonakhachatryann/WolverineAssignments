#include <string>
#include <vector>

//65. Valid Number
//time complexity O(s.size)
//space complexity O(1)
bool isNumber(std::string s) {
        bool number_seen = false;
        bool e_seen = false;
        bool dot_seen = false;
        bool number_after_e_seen = true;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                number_seen = true;
                number_after_e_seen = true;
            } 
            else if (s[i] == 'e' || s[i] == 'E') {
                if (e_seen || !number_seen) {
                    return false;
                }
                e_seen = true;
                number_after_e_seen = false;
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (i != 0) {
                    if (s[i - 1] != 'e' && s[i - 1] != 'E') {
                        return false;    
                    }
                }
            }
            else if (s[i] == '.') {
                if (dot_seen || e_seen) {
                    return false;
                }
                dot_seen = true;
            }
            else {
                return false;
            }
        }
        return number_seen && number_after_e_seen;
}

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

//23. Merge k Sorted Lists
//time complexity O()
//space complexity O()
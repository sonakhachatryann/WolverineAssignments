#include <string>

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
class Solution {
public:
    bool isNumber(string s) {
        size_t ptr = 0;
        bool intExist = false;
        bool decExist = false;
        bool symExist = false;
        bool eExist = false;
        while (s[ptr] == ' ' && ptr < s.size()) {
            ptr++;
        }
        while (s[ptr] != ' ' && ptr < s.size()) {
            if (s[ptr] >= '0' && s[ptr] <= '9') {
                intExist = true;
            }
            else if (s[ptr] == '.') {
                if (decExist || eExist) {
                    return false;
                }
                else {
                    decExist = true;
                }
            }
            else if (s[ptr] == 'e' || s[ptr] == 'E') {
                if (!intExist || eExist) {
                    return false;
                }
                else {
                    intExist = false;
                    symExist = false;
                    eExist = true;
                    decExist = false;
                }
            }
            else if (s[ptr] == '+' || s[ptr] == '-'){
                if (symExist || intExist || decExist) {
                    return false;
                }
                else {
                    symExist = true;
                }
            }
            else {
                return false;
            }
            ptr++;
        } 
        while (ptr < s.size()) {
            if (s[ptr] != ' ') {
                return false;
            }
            ptr++;
        }
        return intExist?true:false;
    }
};

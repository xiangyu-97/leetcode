#include <string>
class Solution {
public:
    string decodeString(string s) {
        vector<string> stk;
        size_t ptr = 0;
        while (ptr < s.size()) {
            char c = s[ptr];
            if (isdigit(c)) {
                string digits = getDigits(s,ptr);
                stk.push_back(digits);
            }
            if (isalpha(c) || c == '[') {
                stk.push_back(string(1,s[ptr]));
                ptr++;
            }
            if (c == ']') {
                string subres = "";
                while (stk.back() != "[") {
                    subres = stk.back() + subres;
                    stk.pop_back();
                }
                stk.pop_back();
                int count = stoi(stk.back()); 
                stk.pop_back();
                string ret = "";
                for (int i = 0; i < count; i++) {
                    ret += subres;
                }
                stk.push_back(ret);
                ptr++;
            }
        }
        return getString(stk);
    }

    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector <string> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }
};

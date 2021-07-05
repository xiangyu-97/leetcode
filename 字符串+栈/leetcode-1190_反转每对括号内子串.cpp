class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> stk;
        size_t ptr = 0;
        while (ptr < s.size()) {
            char c = s[ptr];
            if (isalpha(c) || c == '(') {
                stk.push_back(s[ptr++]);
            }
            if (c == ')') {
                deque<char> temp;
                while (stk.back() != '(') {
                    temp.push_back(stk.back());
                    stk.pop_back();
                };
                stk.pop_back();
                while (!temp.empty()) {
                    stk.push_back(temp.front());
                    temp.pop_front();
                }
                ptr++;
            }
        }
        return getString(stk);
    }
    string getString(vector <char> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }
};

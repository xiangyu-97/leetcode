class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for (char c:s) {
            if (stk.empty()) {
                stk.push_back(c);
                continue;
            }
            if (c != stk.back()) {
                stk.push_back(c);
            }
            else {
                stk.pop_back();
            }
        }
        return stk;
    }
};

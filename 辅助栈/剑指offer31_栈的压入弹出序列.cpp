class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0) {
            return (popped.size() == 0)?true:false;
        }
        stack<int> s;
        int i = 0, j = 0;
        while (j < popped.size()) {
            if (s.empty()) {
                s.push(pushed[i++]);
                continue;
            }
            if (s.top() == popped[j]) {
                s.pop();
                j++;
                continue;
            }
            if (i < pushed.size()) {
                s.push(pushed[i]);
                i++;
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

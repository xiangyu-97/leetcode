class Solution {
public:
    int clumsy(int n) {
        stack<int> stk;
        stk.push(n);
        n--;

        int index = 0;
        while (n > 0){
            if (index % 4 == 0) {
                int temp = stk.top() * n;
                stk.pop();
                stk.push(temp);
            }
            else if (index % 4 == 1) {
                int temp = stk.top() / n;
                stk.pop();
                stk.push(temp);
            }
            else if (index % 4 == 2) {
                stk.push(n);
            }
            else {
                stk.push(-n);
            }
            n--;
            index++;
        }
        int ans = 0;
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

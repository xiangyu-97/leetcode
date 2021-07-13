class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int> affection(customers.size(),0);
        for(int i = 0; i < customers.size(); i++ ) {
            if (grumpy[i] == 0) {
                affection[i] = 0;
            } 
            else {
                affection[i] = customers[i];
            }
        }
        int startIndex = minaffection(affection, minutes);
        int ans = 0;
        for(int i = 0; i < customers.size(); i++ ) {
            if (i >= startIndex && i < startIndex + minutes) {
                ans += customers[i];
            }
            else {
                ans += customers[i] * (grumpy[i] == 0);
            }
        }
        return ans;
    }

    int minaffection(vector<int> affection, int minutes) {
        int best = 0;
        int curr = 0;
        for(int i = 0; i <  minutes; i++) {
            best += affection[i];
            curr += affection[i];
        }
        int startIndex = 0; 
        int curIndex = 0;
        //滑动窗口写复杂了
        while (curIndex < affection.size() - minutes) {
            if (affection[curIndex + minutes] >= affection[curIndex]) {
                curr =  curr + affection[curIndex + minutes] - affection[curIndex];          
            }
            else {
                curr = 0;        
                for(int i = curIndex + 1; i <= curIndex + minutes; i++) {
                    curr += affection[i];
                }
            }
            best = max(best,curr);
            curIndex++;
            startIndex = (best == curr)? curIndex: startIndex;                           
        }
        return startIndex;
    }
};

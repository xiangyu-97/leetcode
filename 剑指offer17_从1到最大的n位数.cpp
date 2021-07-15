class Solution {
public:
    vector<int> printNumbers(int n) {
        if (n == 0) return {};
        int maxn = pow(10,n);
        vector<int> res;
        for (int i = 1; i < maxn; i++) {
            res.push_back(i);
        }
        return res;
    }

    //n太大，可以考虑字符串模拟
};

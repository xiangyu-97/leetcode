class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

         auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;

        //重要的是状态转移方程
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    if (matches(i,j-1)) {
                       dp[i][j] = dp[i][j-2] || dp[i-1][j];
                    }
                    else {
                        dp[i][j] = dp[i][j-2];
                    } 
                }
                else {
                    if (matches(i,j)) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            char c1 = text1[i - 1];
            for (int j = 1; j <= n; j++) {
                char c2 = text2[j - 1];
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
    
    /* 子数组 */
    int longestCommonSubsequence2(string text1, string text2) {
        int length1 = text1.size() - 1;
        int length2 = text2.size() - 1;
        int best = 0;
        int index = 0;
        while ( index <= length1 - length2) {
            int compIndex = 0;
            int temp = index;
            int cur = 0;
            while ( compIndex <= length2 ) {
                if ( text1[index] == text2[compIndex] ) {
                    cur++;
                    index++;
                    compIndex++;
                } else {
                    best = ( best >= cur ) ? best:cur;
                    compIndex = 0;
                    index = temp + compIndex + 1;
                    break;
                }
            }
        }
        return best;
    }
};

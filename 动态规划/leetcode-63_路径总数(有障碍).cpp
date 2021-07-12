class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m == 0) return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m,vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++) {
            dp[0][i] = 1;
        }  

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
    
    // dfs超时
    int count = 0;
    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m == 0) return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> visited(m,vector<int>(n, 0));
        vector<vector<int>> dirs = {{0,1},{1,0}};
        dfs(obstacleGrid, visited, 0, 0, m-1, n-1, dirs);
        return count;
    }

    void dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>>& visited, int x, int y, int ex, int ey, vector<vector<int>> dirs) {
        if (x == ex && y == ey && obstacleGrid[x][y] == 0) {
            count++;
            return;
        }
        
        for(auto &dir:dirs) {
            int nextx = x + dir[0];
            int nexty = y + dir[1];
            if (nextx <= ex && nexty <= ey && visited[nextx][nexty] == 0 && obstacleGrid[nextx][nexty] == 0) {
                visited[nextx][nexty] = 1;
                dfs(obstacleGrid, visited, nextx, nexty, ex, ey, dirs);
                visited[nextx][nexty] = 0;
            }
        }
        return;
    }
};

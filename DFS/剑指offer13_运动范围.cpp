class Solution {
public:
    int count = 0;
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        dfs(0,0,m,n,k,visited);
        return count;
    }

    void dfs(int x, int y, int m, int n, int k, vector<vector<bool>>& visited) {
        if (!isTrue(x,y,m,n,k,visited)) {
            return;
        }
        count++;
        visited[x][y] = true;
        dfs(x-1,y,m,n,k,visited);
        dfs(x+1,y,m,n,k,visited);
        dfs(x,y-1,m,n,k,visited);
        dfs(x,y+1,m,n,k,visited);
        return;
    }

    bool isTrue(int x, int y, int m, int n, int k, vector<vector<bool>>& visited) {
        if (x >= m || y >= n || x < 0 || y < 0 || visited[x][y] == true) {
            return false;
        }
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x = x / 10;
        }
        while (y > 0) {
            sum += y % 10;
            y = y / 10;
        }
        return (k >= sum);
    }
};

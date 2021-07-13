class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if (m == 0) return false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                //避免引入sign
                if (dfs(word,board,0,i,j)) return true;
            }
        }
        return false;
    }

    bool dfs(string word, vector<vector<char>>& board, int index, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index]) { 
            return false;
        }
        if (index == word.size()-1) {
            return true;
        }
        //不用二维数组visited，降低空间复杂度
        board[x][y] = '\0';
        //不用方向向量dirs，降低空间复杂度
        if (dfs(word,board,index+1, x-1, y) || dfs(word,board,index+1, x+1, y)||dfs(word,board,index+1, x, y-1) || dfs(word,board,index+1, x, y+1)) {
            return true;
        }
        board[x][y] = word[index];
        return false;
    }
};

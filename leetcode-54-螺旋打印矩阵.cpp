class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int leftLine = 0;
        int rightLine = matrix[0].size()-1;
        int upRow = 0;
        int downRow = matrix.size() -1;
        while (leftLine <= rightLine && upRow <= downRow) {
            printOneCircle(matrix,res, leftLine, rightLine, upRow, downRow);
            leftLine++;
            rightLine--;
            upRow++;
            downRow--;
        }
        return res;
    }

    void printOneCircle(vector<vector<int>>& matrix, vector<int>& res, int leftLine, int rightLine, int upRow, int downRow) {
        for (int i = leftLine; i <= rightLine; i++ ) {
            res.push_back(matrix[upRow][i]);
        }
        for (int i = upRow + 1; i <= downRow; i++ ) {
            res.push_back(matrix[i][rightLine]);
        }
        if (upRow == downRow || rightLine == leftLine) return;
        for (int i = rightLine - 1; i >= leftLine; i-- ) {
            res.push_back(matrix[downRow][i]);
        }
        for (int i = downRow - 1; i >= upRow + 1 ; i-- ) {
            res.push_back(matrix[i][leftLine]);
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        verRotate(matrix);
        diaRotate(matrix);
    }

    void verRotate(vector<vector<int>>& matrix) {        
        for (int row = 0; row < matrix.size(); row++) {
            int leftline = 0;
            int rightline = matrix[0].size()-1;
            while (leftline < rightline) {
                int temp = matrix[row][rightline];
                matrix[row][rightline] = matrix[row][leftline];
                matrix[row][leftline] = temp;
                leftline++;
                rightline--;
            }
        }    
    }
    void diaRotate(vector<vector<int>>& matrix) {
        int border = matrix[0].size()-1;
        for (int first = 0; first < matrix.size()-1;first++) {
            int second = 0;
            while (second < border - first) {
                int temp = matrix[border-second][border-first];
                matrix[border-second][border-first] = matrix[first][second];
                matrix[first][second] = temp;
                second++;
            }
        }
    }
};

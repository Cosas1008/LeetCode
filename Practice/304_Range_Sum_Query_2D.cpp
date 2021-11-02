/*
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle 
defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
*/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; j++)
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] + matrix[i][j] - dp[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 > row2) return sumRegion(row2, col1, row1, col2);
        if(col1 > col2) return sumRegion(row1, col2, row2, col1);
        row1 = max(0, row1), row2 = min(m-1, row2);
        col1 = max(0, col1), col2 = min(n-1, col2);
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
    }
private:
    int m, n;
    vector<vector<int>> dp;
};

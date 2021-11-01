/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, 
the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for(int i = 1; i < m; ++i)
            for(int j = 0; j < n; ++j)
                A[i][j] += min({A[i-1][max(0, j-1)], A[i-1][j], A[i-1][min(j+1, n-1)]});
        return *min_element(begin(A[m - 1]), end(A[m - 1]));;
    }
};
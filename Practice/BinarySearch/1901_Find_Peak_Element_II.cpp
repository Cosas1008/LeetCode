/*
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int minCol = 0, maxCol = mat[0].size()-1, m = mat.size(), n = mat[0].size();
        while(minCol <= maxCol){ // <= is important here
            int midCol = minCol + (maxCol - minCol) / 2;
            int maxRow = 0;
            for(int row = 1; row < m; ++row)
                maxRow = mat[row][midCol] >= mat[maxRow][midCol]? row : maxRow;
            
            bool leftIsBig  = midCol-1 >= minCol && mat[maxRow][midCol-1] > mat[maxRow][midCol];
            bool rightIsBig = midCol+1 <= maxCol && mat[maxRow][midCol+1] > mat[maxRow][midCol];
            
            if(!leftIsBig && !rightIsBig)
                return {maxRow, midCol};
            else if(rightIsBig)
                minCol = midCol+1;
            else
                maxCol = midCol-1;
        }
        return {-1,-1};
    }
};
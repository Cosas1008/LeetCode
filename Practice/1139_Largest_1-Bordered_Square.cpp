/*
Given a 2D grid of 0s and 1s, return the number of elements in the largest square
subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
Hint:
1 <= grid.length <= 100
1 <= grid[0].length <= 100
Hint : Create auxillary horizontal and vertical arrays first
*/
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> hor(m+1, vector<int>(n+1, 0)), ver(m+1, vector<int>(n+1, 0));
        for (int i=0; i<m; i++) { 
            for (int j=0; j<n; j++) { 
                if (grid[i][j] == 1) 
                { 
                    hor[i][j] = (j==0)? 1: hor[i][j-1] + 1;   // auxillary horizontal array
                    ver[i][j] = (i==0)? 1: ver[i-1][j] + 1;  // auxillary vertical array
                } 
            }
        } 
            
        for (int i = m-1; i>=0; i--) { 
            for (int j = n-1; j>=0; j--) { 
                int small = min(hor[i][j], ver[i][j]);  // choose smallest of horizontal and vertical value
                while (small > res) { 
                    if (ver[i][j-small+1] >= small &&  hor[i-small+1][j] >= small)  // check if square exists with 'small' length
                        res = small; 
                    small--; 
                } 
            } 
        } 
        return res*res; 
    }
};
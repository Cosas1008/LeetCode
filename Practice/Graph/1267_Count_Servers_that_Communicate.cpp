/*
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
communicate: same row/col
*/
class Solution {
public:
    // brute force
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<int> row(m, 0), col(n, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] && (row[i] > 1 || col[j] > 1))
                    res++;
            
        return res;
    }
};
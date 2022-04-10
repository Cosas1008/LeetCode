/*
A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
*/
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            int l1 = i, l2;
            for(int j = 0; j < m; ++j){
                l2 = l1 + grid[j][l1];
                if(l2 < 0 || l2 == n || grid[j][l1] != grid[j][l2]){ // key is to have grid[j][l1] != grid[j][l2]
                    l1 = -1;
                    break;
                }
                l1 = l2;
            }
            ans.push_back(l1);
        }
        return ans;
    }
};
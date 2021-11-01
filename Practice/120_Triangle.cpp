/*
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
*/
class Solution {
public:
    // Bottom-Up
    int minimumTotal(vector<vector<int>>& T) {
        int m = T.size();
        for(int i = m-2; i >= 0; --i)
            for(int j = 0; j < i+1; ++j)
                T[i][j] += min(T[i+1][j], T[i+1][min(j+1, i+1)]);
        return T[0][0];
    }
};
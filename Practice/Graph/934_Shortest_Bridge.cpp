/*
Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
*/
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        // Paint two different color
        for(int i = 0, found = 0; !found && i < A.size(); ++i)
            for(int j = 0; !found && j < A[0].size(); ++j)
                found = paint(A, i, j);
        // Find the min color
        for(int color = 2; ; color++)
            for(int i = 0; i < A.size(); ++i)
                for(int j = 0; j < A[0].size(); ++j)
                    if(A[i][j] == color && (
                        expand(A, i-1, j, color) || expand(A, i+1, j, color) ||
                        expand(A, i, j-1, color) || expand(A, i, j+1, color)))
                        return color - 2;
    }
    int paint(vector<vector<int>>& A, int i, int j){
        if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || A[i][j] != 1) return 0;
        A[i][j] = 2;
        return 1 + paint(A, i+1, j) + paint(A, i, j+1) + paint(A, i-1, j) + paint(A, i, j-1);
    }
    bool expand(vector<vector<int>>& A, int i, int j, int color){
        if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size()) return false;
        if(A[i][j] == 0) A[i][j] = color+1;
        return A[i][j] == 1;
    }
};
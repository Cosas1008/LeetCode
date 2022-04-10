/*
Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).
*/
class Solution {
public:
    int minSideJumps(vector<int>& A) {
        int dp[] = {1, 0, 1};
        for(int& a : A){
            if(a != 0)
                dp[a-1] = 1e6; // max
            for(int i = 0; i < 3; ++i)
                if(a-1 != i)
                    dp[i] = min(dp[i], min(dp[(i+1)%3], dp[(i+2)%3]) + 1);
        }
        return min({dp[0], dp[1], dp[2]});
    }
};
/*
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.

At the end of the game, there is at most one stone left.
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& A) {
        bitset<1501> dp = {1};
        int sumA = 0;
        for(int a : A){
            sumA += a;
            for(int j = min(1500, sumA); j >= a; --j)
                dp[j] |= dp[j-a];
        }
        for(int i = sumA/2; i >= 0; --i)
            if(dp[i]) return sumA - i - i;
        return 0;
    }
};
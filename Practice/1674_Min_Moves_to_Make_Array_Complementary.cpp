/*
The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. 
For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.

Input: nums = [1,2,4,3], limit = 4
Output: 1
Explanation: In 1 move, you can change nums to [1,2,2,3].
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.

Input: nums = [1,2,2,1], limit = 2
Output: 2
Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot change any number to 3 since 3 > limit.

there are 5 different situation for every such pair (A, B), given different target T.

1. 2 <= T < min(A, B) + 1, we need 2 operations to make both A, B smaller
2. min(A, B) + 1 <= T < A + B, we need 1 operation to make the larger one out of A and B smaller
3. T = A + B, we need 0 operation
4. A + B < T <= max(A, B) + limit, we need 1 operation to make the smaller one out of A and B larger
5. max(A, B) + limit < T <= 2 * limit, we need 2 operation to make both A, B larger
*/
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> delta(2*limit + 2, 0);
        int n = nums.size();
        for(int i = 0; i < n/2; ++i){
            int a = nums[i], b = nums[n - 1 - i];
            delta[2] += 2;
            delta[min(a,b) + 1]--;
            delta[a + b]--;
            delta[a + b + 1]++;
            delta[max(a,b) + limit + 1]++;
        }
        int res = 2 * n, curr = 0;
        for(int i = 2; i <= 2 * limit; ++i){
            curr += delta[i];
            res = min(res, curr);
        }
        return res;
    }
};
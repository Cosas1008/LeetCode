/*
Input: nums = [1,2,3,2,2,1,3], k = 3
Output: [3,2,2,2,3]
Explanation: The number of distinct elements in each subarray goes as follows:
- nums[0:2] = [1,2,3] so ans[0] = 3
- nums[1:3] = [2,3,2] so ans[1] = 2
- nums[2:4] = [3,2,2] so ans[2] = 2
- nums[3:5] = [2,2,1] so ans[3] = 2
- nums[4:6] = [2,1,3] so ans[4] = 3
*/
class Solution {
    vector<int> distinctNumber(vector<int> A, int k){
        vector<int> ans;
        unordered_map<int,int> count;
        for(int i = 0; i < A.size(); i++){
            count[A[i]]++;
            if(i >= k){
                count[A[i-k]]--;
            }
            if(i+1 >= k){
                ans.push_back(count.size());
            }
        }
        return ans;
    }
};
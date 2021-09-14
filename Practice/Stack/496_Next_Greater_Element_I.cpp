/*
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and 
determine the next greater element of nums2[j] in nums2. 
If there is no next greater element, then the answer for this query is -1.

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> mono;
        unordered_map<int,int> m;
        for(int n : nums2){
            while(mono.size() && mono.top() < n){
                m[mono.top()] = n;
                mono.pop();
            }
            mono.push(n);
        }
        for(int n : nums1)
            ans.push_back(m.count(n)? m[n] : -1);
        return ans;
    }
};
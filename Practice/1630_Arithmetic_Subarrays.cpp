/*
def : arithmetic s[i+1] - s[i] == s[1] - s[0] for all valid i.
You are given an array of n integers, nums, and two arrays of m integers each, l and r, 
representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Example: 
Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
Output: [true,false,true]
Explanation:
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
*/
class Solution {
public:
    // Time Complexity O(m * n * log n)
    vector<bool> checkArithmeticSubarrays(vector<int>& A, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans(n, false);
        for(int i = 0; i < n; i++){
            vector<int> B(A.begin() + l[i], A.begin() + r[i]+1);
            sort(B.begin(), B.end());
            int j = 2;
            for(; j <= n.size(); j++){
                if(B[j] - B[j-1] != B[1] - B[0])
                    break;
            }
            ans[i] = j == B.size();
        }
        return ans;
    }
    // Alternate Optimized
    // https://leetcode.com/problems/arithmetic-subarrays/discuss/910421/C%2B%2B-Two-Approaches-(140-vs-28ms)
    // Time Complexity O(m * n) w/o sort
    vector<bool> checkArithmeticSubarrays(vector<int>& A, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans;
        for(int i = 0; i < m; i++){
            int min_e = INT_MAX, max_e = INT_MIN, len = r[i] - l[i] + 1, j = l[i];
            for(; j <= r[i]; j++){
                min_e = min(min_e, A[j]);
                max_e = max(max_e, A[j]);
            }
            if(max_e == min_e)
                ans.push_back(true);
            else if((max_e - min_e) % (len - 1))
                ans.push_back(false);
            else{
                vector<bool> diff(len);
                int pat = (max_e - min_e) / (len - 1); // each dif
                for(j = l[i]; j <= r[i]; ++j){
                    if((A[j] - min_e) % pat || diff[(A[j] - min_e) / pat])
                        break;
                    diff[(A[j] - min_e) / pat] = true;
                }
                ans.push_back(j > r[i]);
            }
        }
        return ans;
    }
};
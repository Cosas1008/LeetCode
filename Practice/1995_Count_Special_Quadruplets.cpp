/*
Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:

nums[a] + nums[b] + nums[c] == nums[d], and
a < b < c < d
*/
class Solution {
public:
    // O(N^3)
    int countQuadruplets(vector<int>& A) {
        int n = A.size(), cnt = 0;
        unordered_map<int, int> mp;
        mp[A[n-1]] = 1;
        for(int i = n - 2; i > 1; --i){
            for(int j = i - 1; j > 0; --j){
                for(int k = j - 1; k > -1; --k){
                    if(mp.count(A[i] + A[j] + A[k]))
                        cnt += mp[A[i] + A[j] + A[k]];
                }
            }
            mp[A[i]]++;
        }
        return cnt;
    }
};
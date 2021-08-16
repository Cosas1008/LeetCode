/*
Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp;
        for(int a : A){
            for(int b : B){
                ++mp[a+b];
            }
        }
        int ans = 0;
        for(int c : C){
            for(int d : D){
                if(mp.count(-c-d) != 0)
                    ans+=mp[-c-d];
            }
        }
        return ans;
    }
};
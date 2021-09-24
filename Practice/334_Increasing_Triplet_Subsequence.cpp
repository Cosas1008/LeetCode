/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& A) {
        vector<int> lis;
        for(auto a : A){
            auto it = lower_bound(lis.begin(), lis.end(), a);
            if(it == lis.end()) lis.push_back(a);
            else *it = a;
        }
        return lis.size() > 2;
    }
};
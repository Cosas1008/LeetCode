/*
Input: n = 2, start = 3
Output: [3,2,0,1]
Explanation: The binary representation of the permutation is (11,10,00,01). 
All the adjacent element differ by one bit. Another valid permutation is [3,1,0,2]
*/
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        for(int i = 0; i < 1<<n; ++i)
            res.push_back(start ^ i ^ i >> 1);
        return res;
    }
};
/*
Input: segments = [[1,4,5],[4,7,7],[1,7,9]]
Output: [[1,4,14],[4,7,16]]
Explanation: The painting can be described as follows:
- [1,4) is colored {5,9} (with a sum of 14) from the first and third segments.
- [4,7) is colored {7,9} (with a sum of 16) from the second and third segments.
*/
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long> m; // use map here instead of unordered_map
        for(auto seg : segments){
            m[seg[0]] += seg[2];
            m[seg[1]] -= seg[2];
        }
        vector<vector<long long>> ret;
        long long cur = 0, begin = 0, end = 0, pre = 0;
        for(auto it : m){
            pre = cur;
            cur += it.second;
            end = it.first;
            if(pre > 0)
                ret.push_back({begin, end, pre});
            begin = it.first;
        }
        return ret;
    }
};
/*
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// just like 452. Minimum Number of Arrows to Burst Balloons
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(begin(intervals), end(intervals), [](const vector<int>& lh, const vector<int>& rh){
            return lh[0] < rh[0];
        });
        int pre = 0;
        for(int cur = 1; cur < intervals.size(); ++cur){
            if(intervals[cur][0] < intervals[pre][1]){ // pre end > cur start
                ans++;
                if(intervals[cur][1] < intervals[pre][1]) pre = cur;
            }
            else pre = cur;
        }
        return ans;
    }
};
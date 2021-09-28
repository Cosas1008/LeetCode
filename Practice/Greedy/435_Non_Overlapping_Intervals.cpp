/*
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
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
// Solve 56 immediately
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(int i = 0; i < intervals.size(); i++){
            mp[intervals[i][0]] = i;
        }
        vector<int> ans(intervals.size(), -1);
        for(int i = 0; i < intervals.size(); i++){
            if(mp.lower_bound(intervals[i][1])!=end(mp)){
                ans[i] = mp.lower_bound(intervals[i][1])->second;
            }
        }
        return ans;
    }
};
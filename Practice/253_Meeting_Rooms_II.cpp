/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: 
[[0, 30],[5, 10],[15, 20]]

Output: 2
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        unordered_map<int,int> m;
        for(int interval : intervals){
            m[interval[0]]++;
            m[interval[1]]--;
        }
        int ret = 0, rooms;
        for(auto it : m){
            ret = max(ret, rooms += it.second);
        }
        return ret;
    }
    // method 2 : min heap
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int interval : intervals){
            if(!q.empty() && q.top() > interval[0]) q.pop();
            q.push(interval[1]);
        }
        return q.size();
    }
};
/*
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> s;
        s.push_back(points[0]);
        for(int i = 1; i < points.size(); i++){
            if(s.size() && points[i][0] <= s.back()[1]){
                s.back()[1] = min(s.back()[1], points[i][1]); // key is to update end with min value
            }else{
                s.push_back(points[i]);
            }
        }
        return s.size();
    }
};
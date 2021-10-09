/*
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
1. 1 <= points.length <= 500
2. points[i].length == 2
3. 0 <= xi, yi <= 4 * 104
4. All the given points are unique.
*/
class Solution {
public:
    // hash map + set
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> x;
        int res = INT_MAX;
        for(auto p : points) x[p[0]].insert(p[1]);
        for(auto i = x.begin(); i != x.end(); ++i)
            for(auto j = next(i); j != x.end(); ++j){
                if(i->second.size() < 2 || j->second.size() < 2) continue; // means at same X, only 1 y
                vector<int> y; // Insert into y if both i and j share the same y value
                set_intersection(begin(i->second), end(i->second), begin(j->second), end(j->second), back_inserter(y));
                for(int k = 1; k < y.size(); ++k)
                    res = min(res, abs(j->first - i->first) * (y[k] - y[k-1]));
            }
        return res == INT_MAX? 0 : res;
    }
};
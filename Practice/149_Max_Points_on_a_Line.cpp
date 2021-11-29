/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
return the maximum number of points that lie on the same straight line.
* All the points are unique.
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i = 0; i < n; ++i){
            unordered_map<string, int> store;
            for(int j = i+1; j < n; ++j){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int gc = gcd(dx, dy);
                string s = to_string(dx/gc) + '_' + to_string(dy/gc);
                store[s]++;
            }
            for(auto it = store.begin(); it != store.end(); ++it)
                ans = max(ans, it->second + 1);
        }
        return ans;
    }
    int gcd(int a, int b){
        return (b==0)? a : gcd(b, a % b);
    }
};
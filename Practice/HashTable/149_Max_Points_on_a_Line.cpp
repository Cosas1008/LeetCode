class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            map<string, int> store;
            int dup = 1;
            for(int j = i+1; j < n; j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                    dup++;
                }else{
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];
                    int gc = gcd(dx, dy);

                }
                string s = str(dx/gc) + '_' + str(dy/gc);
                store[s]++;
            }
            ans = max(ans, dup);
            for(auto it = store.begin(); it != store.end(); it++){
                ans = max(ans, it->second + dup);
            }
        }

        return ans;
    }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};
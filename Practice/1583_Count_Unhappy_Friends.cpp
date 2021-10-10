/*
You are given a list of preferences for n friends, where n is always even.
A friend x is unhappy if x is paired with y and there exists a friend u who is paired with v but:
x prefers u over y, and u prefers x over v.
Input: n = 4, preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], pairs = [[0, 1], [2, 3]]
Output: 2
Explanation:
Friend 1 is unhappy because:
- 1 is paired with 0 but prefers 3 over 0, and
- 3 prefers 1 over 2.
Friend 3 is unhappy because:
- 3 is paired with 2 but prefers 1 over 2, and
- 1 prefers 3 over 0.
Friends 0 and 2 are happy.
*/
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<unordered_map<int,int>> m(n);
        vector<int> dist(n);
        int res = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < preferences[i].size(); ++j)
                m[i][preferences[i][j]] = j;
        for(auto& p : pairs){
            dist[p[0]] = m[p[0]][p[1]];
            dist[p[1]] = m[p[1]][p[0]];
        }
        for(int i = 0; i < n; ++i){
            for(int d = 0; d < dist[i]; ++d){
                int j = preferences[i][d];
                for(int d1 = 0; d1 < dist[j]; ++d1){
                    if(i == preferences[j][d1]){
                        ++res;
                        d = d1 = n;
                    }
                }
            }
        }
        return res;
    }
};
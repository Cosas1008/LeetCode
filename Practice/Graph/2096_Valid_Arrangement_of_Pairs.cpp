/*
Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 9 == 9 = start1 
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3
* Hint: store adjacent pairs
*/
class Solution {
public:
    map<int, vector<int>> adj; // key
    vector<vector<int>> ans;
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,int> mp;
        for(auto& p : pairs){
            adj[p[0]].push_back(p[1]);
            mp[p[0]]++;
            mp[p[1]]--;
        }
        // 1 means start -1 means end
        int start = -1;
        for(auto& it : mp){
            if(it.second > 0) start = it.first;
        }
        if(start == -1)
            start = pairs[0][0];
        dfs(start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void dfs(int node){
        while(adj[node].size()){
            int next = adj[node].back();
            adj[node].pop_back();
            dfs(next);
            ans.push_back({node, next});
        }
    }
};
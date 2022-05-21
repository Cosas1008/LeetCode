/*
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
*/
class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> g;
    vector<double> ans;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        for(int i = 0; i < n; ++i){
            string a = equations[i][0], b = equations[i][1];
            g[a].push_back({b,values[i]});
            g[b].push_back({a,(double)1/values[i]});
        }
        for(auto query : queries){
            unordered_set<string> visit;
            ans.push_back(helper(visit, query[0], query[1]));
        }
        return ans;
    }
    double helper(unordered_set<string>& visit, string src, string dst){
        if(g.find(src) == g.end() || g.find(dst) == g.end()) return -1;
        if(src == dst) return 1;

        for(auto node : g[src]){
            if(visit.count(node.first)) continue;
            visit.insert(node.first);
            double res = helper(visit, node.first, dst);
            if(res != -1) return res * node.second;
        }
        return -1;
    }
};
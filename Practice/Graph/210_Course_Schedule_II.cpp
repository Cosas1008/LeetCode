/*
You are given an array prerequisites where 
prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
Return the ordering of courses you should take to finish all courses.
*/
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
      vector<vector<int>> g(n, vector<int>());
      vector<int> deg(n, 0);
      for(auto p : pre){
        g[p[1]].push_back(p[0]);
        deg[p[0]]++;
      }
      queue<int> q;
      for(int i = 0 ; i < n; ++i)
        if(deg[i] == 0) q.push(i);
      vector<int> ans;
      while(!q.empty()){
        int cur = q.front(); q.pop();
        // n--;
        ans.push_back(cur);
        for(auto next : g[cur])
          if(--deg[next] == 0) q.push(next);
      }
      return n == 0? ans : vector<int>();
    }
};
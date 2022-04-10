/*
You are given an array prerequisites where 
prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for(auto pre : prerequisites){
            graph[pre[1]].push_back(pre[0]); // available course
            indegree[pre[0]]++;
        }
        queue<int> q;
        // Find start course
        for(int i = 0; i < numCourses; ++i)
            if(indegree[i] == 0)
                q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            ans.push_back(u);
            for(auto n : graph[u]){
                if(--indegree[n] == 0)
                    q.push(n);
            }
        }
        return ans.size() == numCourses? ans : vector<int>{};
    }
};
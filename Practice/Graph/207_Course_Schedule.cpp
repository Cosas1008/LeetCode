/*
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
*/
// BFS ( https://leetcode.com/problems/course-schedule/discuss/58509/C%2B%2B-BFSDFS )
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> deg = computeIndegrees(g);
        for(int i = 0 ; i < numCourses; ++i){
            int j = 0;
            for(; j < numCourses; ++j){
                if(!deg[j]) break;
            }
            if( j == numCourses) return false;
            deg[j]--;
            for(int v : g[j])
                deg[v]--;
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites){
        graph g(numCourses);
        for(auto p : prerequisites){
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    vector<int> computeIndegrees(graph& g){
        vector<int> degree(g.size(), 0);
        for(auto node : g){
            for(int v : node)
                degree[v]++;
        }
        return degree;
    }
};
// Topological sort
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n, vector<int>());
        vector<int> deg(n, 0);
        for(auto& p : pre){
            g[p[1]].push_back(p[0]);
            deg[p[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(deg[i] == 0) q.push(i);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            n--;
            for(auto next : g[cur])
                if(--deg[next] == 0) q.push(next);
        }
        return n == 0; // all not being pushed
    }
};
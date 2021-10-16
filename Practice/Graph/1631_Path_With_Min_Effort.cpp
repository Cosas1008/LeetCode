//A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
class Solution {
public:
    // Dijkstra's Algo
    // Time: O(ElogV) = O(M*N log M*N)
    // Space O(M*N)
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int dir[5] = {0, 1, 0, -1, 0};
        priority_queue<vector<int>, vector<vector<int>>, greater<> > pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        pq.emplace(vector<int>{0, 0, 0});
        while(pq.size()){
            vector<int> tp = pq.top(); pq.pop();
            int alter = tp[0], x = tp[1], y = tp[2];
            if(dist[x][y] < alter) continue;
            if(x == m-1 && y == n-1) return alter;
            for(int i = 0; i < 4; ++i){
                int dx = x + dir[i], dy = y + dir[i+1];
                if(dx == m || dy == n || dx < 0 || dy < 0) continue;
                int newDist = max(alter, abs(heights[dx][dy] - heights[x][y]));
                if(dist[dx][dy] > newDist){
                    dist[dx][dy] = newDist;
                    pq.emplace(vector<int>{newDist, dx, dy});
                }
            }
        }
        return 0; // unreachable
    }
};
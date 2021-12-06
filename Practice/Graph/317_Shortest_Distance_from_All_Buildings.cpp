/*
[
[1,0,2,0,1]
[0,0,0,0,0]
[0,0,1,0,0]
]
0 -> empty land
1 -> building cannot pass
2 -> obstacle cannot pass
Return location of house on empty land(0) which reaches all buildings in the shortest amount of distance
*/
class Solution {
public:
    int shortestDistance(vector<vector<int>> grid){
        m = grid.size();
        n = grid[0].size();
        reaches.resize(m, vector<int>(n, 0));
        dist.resize(m, vector<int>(n, m+n));
        int totalBuilding = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == 1){
                    dfs(grid, i, j, 0, totalBuilding);
                    totalBuilding++;
                }
        int minDist = INT_MAX;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(reaches[i][j] == totalBuilding && dist[i][j] < minDist)
                    minDist = dist[i][j];
                    
        return minDist == INT_MAX? -1 : minDist;
    }
    // wrong approach here
    void dfs(vector<vector<int>>& grid, int x, int y, int d, int k){
        if(reaches[x][y] & (1 << k)) return;
        dist[x][y] = d;
        reaches[x][y] |= 1 << k;
        for(int i = 0; i < 4; ++i){
            int dx = x + dir[i], dy = y + dir[i+1];
            if(dx < 0 || dy < 0 || dx == m || dy == n || grid[dx][dy] != 0) continue;
            dfs(grid, dx, dy, d+1);
        }
    }
private:
    int m, n;
    vector<vector<int>> reaches, dist;
    vector<int> dir = {0, 1, 0, -1, 0};
}
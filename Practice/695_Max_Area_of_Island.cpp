// Store previous visit ( Straight forward method )
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        int max_island = 0;
        vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visit[i][j] == false){
                    if(grid[i][j] == 1){  // island
                        int area = 1;
                        queue<vector<int>> q;
                        q.push({i,j});
                        while(!q.empty()){
                            int row = q.front()[0];
                            int col = q.front()[1];
                            visit[row][col] = true;
                            // 4-directions
                            for(auto dir : directions){
                                if(  row + dir[0] >= 0 &&  row + dir[0] < m  &&
                                     col + dir[1] >= 0 &&  col + dir[1] < n  &&
                                     !visit[row+dir[0]][col+dir[1]]
                                  ){
                                    if(grid[row+dir[0]][col+dir[1]] == 1){
                                        area++;
                                        q.push({row+dir[0],col+dir[1]});
                                    }
                                    visit[row+dir[0]][col+dir[1]] = true;
                                }
                            }
                            q.pop(); // remove from queue
                        }
                        if(area > max_island){
                            max_island = area;
                            // cout << "Find " << area << endl;
                        }
                    }
                    visit[i][j] = true;
                }
            }
        }
        return max_island;
    }
};

// Better way with recursive call
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++)
            if(grid[i][j] == 1)max_area = max(max_area, AreaOfIsland(grid, i, j));
    return max_area;
}

int AreaOfIsland(vector<vector<int>>& grid, int i, int j){
    if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
        grid[i][j] = 0;
        return 1 + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
    }
    return 0;
}
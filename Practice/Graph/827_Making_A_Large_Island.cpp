/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.
*/
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
        int index = 2, res = 0;
        unordered_map<int,int> area;
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                if(grid[x][y] == 1){
                    area[index] = dfs(grid, x, y, index);
                    res = max(res, area[index++]);
                }
            }
        }
        // traverse 0 cells and count biggest island
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                if(grid[x][y] == 0){
                    unordered_set<int> seen;
                    int total = 1;
                    for(auto p : move(x,y)){
                        index = grid[p.first][p.second];
                        if(index > 1 && seen.count(index) == 0){
                            seen.insert(index);
                            total += area[index];
                        }
                    }
                    res = max(res, total);
                }
            }
        }
        return res;
    }
    bool valid(int x, int y){
        return x >= 0 && y >= 0 && x < N && y < N;
    }

    vector<pair<int,int>> move(int x, int y){
        vector<pair<int,int>> res;
        int dir[5] = { 0 , 1 , 0 , -1 , 0};
        for(int i = 0; i < 4; i++){
            if(valid(x + dir[i], y + dir[i+1]))
                res.emplace_back(x+dir[i], y+dir[i+1]);
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int index){
        int area = 0;
        grid[x][y] = index;
        for(auto p : move(x,y)){
            if(grid[p.first][p.second] == 1)
                area += dfs(grid, p.first, p.second, index);
        }
        return area + 1;
    }
private:
    int N;
};
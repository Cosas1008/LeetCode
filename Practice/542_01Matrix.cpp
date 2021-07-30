/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // bfs O(N^2)
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0)
                    q.emplace(i,j);
                else
                    mat[i][j] = m + n;
            }
        }
        int dir[5] = {0 , 1, 0, -1, 0};
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int dx = x + dir[i], dy = y + dir[i+1];
                if(dx >= 0 && dy >= 0 && dx < m && dy < n){
                    if(mat[dx][dy] == m+n) q.emplace(dx,dy);
                    mat[dx][dy] = min(mat[dx][dy], mat[x][y] + 1);
                }
            }
        }
        return mat;
    }
};
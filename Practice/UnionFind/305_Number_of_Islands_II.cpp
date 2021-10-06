/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
*/
// Keyword: Union Find
class Solution {
public:
    // Union find
    int numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        vector<int> roots(m*n, -1);
        int dirs[5] = {0,1,0,-1,0};
        int cnt = 0;
        for(auto pos : positions){
            int id = n * pos[0] + pos[1]; // unique hash key
            if(root(id) != -1){
                res.push_back(cnt);
                continue;
            }
            root[id] = id;
            ++cnt;
            for(int i = 0; i < 4; ++i) { // 4-directions
                int x = pos[0] + dirs[i], y = pos[1] + dirs[i+1], cur_id = n * x + y;
                if(x < 0 || x >= m || y < 0 || y >= n || root[cur_id] == -1) continue;
                int p = find(roots, cur_id), q = find(roots, id);
                if(p != q){
                    root[p] = q;
                    --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    int find(vector<int>& roots, int id){
        return (id == roots[id])? id: find(roots, roots[id]);
    }
}
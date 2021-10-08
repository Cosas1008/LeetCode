/*
You want to plant one of 4 types of flowers.
All gardens have at most 3 paths coming into or leaving it.

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].
*/
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Because there is no node that has more than 3 neighbors, always one possible color to choose.
        vector<int> res(n);
        vector<vector<int>> G;
        for(auto p : paths){
            G[p[0]-1].push_back(p[1]-1);
            G[p[1]-1].push_back(p[0]-1);
        }
        for(int i = 0; i < n; ++i){
            int colors[5] = {};
            for(int j : G[i])
                colors[res[j]] = 1;
            // Greedily choose a color from candidates
            for(int c = 4; c > 0; --c){
                if(!colors[c]){
                    res[i] = c;
                    break;
                }
            }
        }
        return res;
    }
};
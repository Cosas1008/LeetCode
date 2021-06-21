/*
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Min cost path
Dijkstra's
*/
class Solution {
public:
    struct mycomp {
        bool operator()(const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] > rhs[0];
        }
    };
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, true));
        priority_queue<vector<int>, vector<vector<int>>, mycomp> pq;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        vector<int> dir = {0, 1, 0 , -1 , 0};

        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            vector<int> tmp = pq.top();
            pq.pop();
            int time = tmp[0];
            int i = tmp[1], j = tmp[2];
            // cout << "visit [" << i << "][" << j << "]" << endl;
            visit[i][j] = false;
            cost[i][j] = time;

            if(i == j && i == n-1)
                break;

            for(int k = 0; k < 4; k++){
                int x = i + dir[k];
                int y = j + dir[k+1];
                if(x >= 0 && x < n && y >= 0 && y < n && visit[x][y]){
                    int t = max(time, grid[x][y]);
                    pq.push({t, x, y});
                    visit[x][y] = false;
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << cost[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return cost[n-1][n-1];
    }
};
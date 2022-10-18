
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> step{n, m-1};
        int di = 0; // direction
        int x = 0, y = -1; // position
        while(step[di % 2]){
            for(int i = 0; i < step[di % 2]; ++i){
                x += dir[di][0]; y += dir[di][1];
                res.push_back(matrix[x][y]);
            }
            step[di % 2]--;
            di = ++di % 4;
        }
        return res;
    }
    // Simple but too much code
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, top = 0, right = n-1, bottom = m-1;
        int dir = 0;
        vector<int> ans;
        while(left <= right && top <= bottom){
            // left to right
            if(dir == 0){
                for(int i = left; i <= right; i++){
                    ans.push_back(matrix[top][i]);
                }
                dir++;
                top++;
            }
            // top to bottom
            if(dir == 1){
                for(int i = top; i <= bottom; i++){
                    ans.push_back(matrix[i][right]);
                }
                dir++;
                right--;
            }
            // right to left
            if(dir == 2){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                dir++;
                bottom--;
            }
            // bottom to top
            if(dir == 3){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                dir = 0;
                left++;
            }
        }
        ans.resize(m*n);
        return ans;
    }
};
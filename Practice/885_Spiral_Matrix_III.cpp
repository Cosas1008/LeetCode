class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int dir[5] = { 0, 1, 0, -1, 0};
        int len = 0, d = 0;
        ans.push_back({rStart, cStart});
        while(ans.size() < rows * cols){
            if(d == 0 || d == 2) len++; // when moving left or right
            for(int i = 0 ; i < len; i++){
                rStart += dir[d];
                cStart += dir[d+1];
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    ans.push_back({rStart, cStart});
            }
            d = (d+1) % 4;
        }
        return ans;
    }
};
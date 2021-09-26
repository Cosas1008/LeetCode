class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n-1, top = 0, bottom = n-1;
        int direct = 0, value = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        while(left <= right && top <= bottom){
            // left to right
            if(direct == 0){
                for(int i = left; i <= right; ++i)
                    ans[top][i] = value++;
                ++direct;
                ++top;
            // top to bottom
            }else if(direct == 1){
                for(int i = top; i <= bottom; ++i)
                    ans[i][right] = value++; 
                ++direct;
                --right;
            // right to left
            }else if(direct == 2){
                for(int i = right; i >= left; --i)
                    ans[bottom][i] = value++;
                ++direct;
                --bottom;
            // bottom to top
            }else{
                for(int i = bottom; i >= top; --i)
                    ans[i][left] = value++;
                direct = 0;
                ++left;
            }
        }
        return ans;
    }
};
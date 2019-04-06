class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row, col;
        row = grid.size();
        col = grid[0].size();
        int perimeter = 0;
        for(int i = 0; i < row; i ++){
            for(int j = 0; j < col; j++){
                int land = grid[i][j];
                if(land == 1){
                    //island check the surrounding
                    if(j == 0){
                        perimeter ++;
                    }else {
                        if (grid[i][j - 1] == 0) //left
                            perimeter++;
                    }
                    if(j == col-1) {
                        perimeter++;
                    }else{
                        if(grid[i][j+1] == 0) // right
                            perimeter ++;
                    }
                    if(i == 0){
                        perimeter ++;
                    }else{
                        if(grid[i-1][j] == 0) // top
                            perimeter ++;
                    }
                    if(i == row-1){
                        perimeter++;
                    }else{
                        if(grid[i+1][j] == 0) // button
                            perimeter ++;
                    }
                }
            }
        }
        return perimeter;
    }

};

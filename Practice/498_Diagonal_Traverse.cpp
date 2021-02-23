class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if(n == 0) return ans;
        int m = matrix[0].size();
        
        vector<vector<int>> rank;
        vector<int> one(1,0);
        // initialize each group
        for(int i = 0; i < m+n - 1; i++){
            rank.push_back(one);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rank[i + j].push_back(matrix[i][j]);
            }
        }
        
        // Remove first at each group
        for(int i = 0; i < rank.size(); i++){
            rank[i].erase(rank[i].begin());
            if(i%2){
                for(int j = 0; j < rank[i].size(); j++){
                    ans.push_back(rank[i][j]);
                    // cout << rank[i][j] << " ";
                }
            }else{
                for(int j = rank[i].size()-1; j >= 0; j--){
                    ans.push_back(rank[i][j]);
                    // cout << rank[i][j] << " ";
                }
            }
            // cout << endl;
        }
        return ans;
    }
};
// Neat!
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                // cout<< matrix[a][a+i] << " : " << matrix[a+i][b] << endl;
                swap(matrix[a][a+i], matrix[a+i][b]);
                // cout<< matrix[a][a+i] << " : " << matrix[b][b-i] << endl;
                swap(matrix[a][a+i], matrix[b][b-i]);
                // cout<< matrix[a][a+i] << " : " << matrix[b-i][a] << endl;
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    }
};

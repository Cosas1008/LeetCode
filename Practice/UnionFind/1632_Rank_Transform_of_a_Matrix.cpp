class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<priority_queue<int>> row(m), col(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int tmp = matrix[i][j];
                row[i].push_back(tmp);
                col[j].push_back(tmp);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int tmp = matrix[i][j];
                int rk = max(getRank(row[i], tmp), getRank(col[j], tmp));
                matrix[i][j] = rk;
            }
        }
        return matrix;
    }
    int getRank(priority_queue<int> pq, int target){
        int rank = 1;
        while(pq.top() != target){
            po.pop();
            rank++;
        }
        return rank;
    }
};

// Try 2
class Solution{
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix){
        int m = matrix.size(), n = matrix[0].size();
        map<int, vector<int>> mp;
        vector<int> rank(m+n, 0);
        vector<vector<int>> ans(m, vector<int>(n)); // matrix size
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[matrix[i][j]].push_back(i * n + j);
            }
        }
        for(auto& it : mp){
            vector<int> root(m+n, 0);
            iota(root.begin(), root.end(), 0);

            vector<int>& v = it.second;
            for(int& a : v){
                int i = a/n, j = a%n; // index i and j
                int r1 = find(root, i), r2 = find(root, j+m);
                root[r1] = r2;        // make row point to column
                rank[r2] = max(rank[r1], rank[r2]);
            }
            auto rank2 = rank;
            for(int& a : v){
                int i = a/n, j = a%n;
                int r = find(root, i);
                ans[i][j] = rank[r] + 1;
                rank2[i] = rank[r] + 1;
                rank2[j+m] = rank[r] + 1;
            }
            rank = move(rank2);
        }
        return ans;
    }
    int find(vector<int>& root, int x){
        if(root[x] != x) root[x] = find(root, root[x]);
        return root[x];
    }
};
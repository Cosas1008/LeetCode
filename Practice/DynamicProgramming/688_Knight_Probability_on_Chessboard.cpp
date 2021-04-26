class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> mem(N, vector<vector<double>>(N, vector<double>(K + 1)));
        return helper(N, K, r, c, mem);
    }
private:
    double helper(int N, int K, int r, int c, vector<vector<vector<double>>>& mem)
    {
        if(r < 0 || c < 0 || r >= N || c >= N) return 0;
        if(K == 0) return 1;    // This must be second statement!!!!
        if(mem[r][c][K] != 0) return mem[r][c][K];
        double p = helper(N, K - 1, r + 1, c + 2, mem) + helper(N, K - 1, r + 2, c + 1, mem) +
                   helper(N, K - 1, r + 1, c - 2, mem) + helper(N, K - 1, r + 2, c - 1, mem) + 
                   helper(N, K - 1, r - 1, c - 2, mem) + helper(N, K - 1, r - 2, c - 1, mem) +
                   helper(N, K - 1, r - 1, c + 2, mem) + helper(N, K - 1, r - 2, c + 1, mem);
        p /= 8;
        mem[r][c][K] = p;
        return p;
    }
};
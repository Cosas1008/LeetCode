class Solution {
public:
    // Time O(8 * sizeof(A) * n)
    int totalHammingDistance(vector<int>& A) {
        int res = 0, n = A.size();
        for(int i = 0; i < 32; ++i){
            int setCount = 0;
            for(int j = 0; j < n; ++j){
                if(A[j] & (1<<i)) setCount++;
            }
            res += setCount * (n - setCount);
        }
        return res;
    }
};
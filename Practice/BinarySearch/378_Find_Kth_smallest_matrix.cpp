class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n  = matrix.size();
      int sm = matrix[0][0];
      int lg = matrix[n-1][n-1];
      while(sm < lg){
        int mid = sm+lg>>1;
        int cnt = 0;
        for(int i = 0, j = n-1; i < n; i++){
          while(j >= 0 && matrix[i][j] > mid) j--;
          cnt += j + 1;
        }
        if(cnt < k)
          sm = mid + 1;
        else
          lg = mid;
      }
      return sm;
    }
};
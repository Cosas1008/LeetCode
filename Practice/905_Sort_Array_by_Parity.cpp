class Solution {
public:
    // Straight forward
    vector<int> sortArrayByParity(vector<int>& A) {
      int l = 0, r = A.size() - 1;
      while(l < r){
        if(A[l] % 2 > A[r] % 2)
          swap(A[l], A[r]);
        while(l < A.size() && A[l] % 2 == 0) l++;
        while(r >= 0 && A[r] % 2 == 1) r--;
      }
      return A;
    }
    // Concise
    vector<int> sortArrayByParity(vector<int>& A) {
      int l = 0, r = A.size() - 1;
      while(l < r){
        if(A[l] % 2){
          swap(A[l], A[r]);
          --r;
        }else{
          ++l;
        }
      }
      return A;
    }
};
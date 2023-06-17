//
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
      int lo = 1;
      int hi = m * n;
      row = m;
      col = n;
      kth = k;
      while(lo < hi){
        int mid = (lo + hi) / 2;
        if(!enough(mid)){
          lo = mid + 1;
        }else{
          hi = mid;
        }
      }
      return lo;
    }
private:
  int row;
  int col;
  int kth;
  bool enough(int mid){
    int count = 0;
    for(int i = 1; i <= row; i++){
      count += min(mid / i, col);
    }
    return count >= kth;
  }
};
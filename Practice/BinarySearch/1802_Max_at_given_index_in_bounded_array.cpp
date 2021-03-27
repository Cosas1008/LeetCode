class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
      maxSum -= n;
      int left = 0;
      int right = maxSum;
      int mid;
      while(left < right){
        mid = (right + left + 1) / 2;
        if(helper(n, index, mid) <= maxSum){
          left = mid;
        }else{
          right = mid - 1;
        }
      }
      return left + 1;
    }
    long helper(int n, int index, int mid){
      int b = max(0, mid - index);
      long res = long(mid + b) * (mid - b + 1) / 2;
      b = max(0, mid - ( n - 1 - index));
      res += long(mid + b) * (mid - b + 1) / 2;
      return res - mid;
    }
};
// (not necessarily with distinct values).
class Solution {
public:
    bool search(vector<int>& A, int target) {
        int n = A.size(), lo = 0, hi = n - 1;
        while(lo <= hi){
            while(lo < hi && A[lo] == A[lo+1]) lo++;
            while(lo < hi && A[hi] == A[hi-1]) hi--;
            int mid = lo + (hi - lo) / 2;
            if(A[mid] == target || A[lo] == target || A[hi] == target) return true;
            if(A[mid] > target){
                if(A[lo] > A[mid] || A[lo] < target)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }else{
                if(A[lo] < A[mid] || A[lo] > target)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return false;
    }
};

// Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
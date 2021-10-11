// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
class Solution{
public:
    int search(vector<int>& A, int target) {
        int n = A.size(), lo = 0, hi = n-1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(A[mid] > A[hi]) lo = mid + 1;
            else hi = mid;
        }
        int rot = lo;
        lo = 0, hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            int realmid = (mid + rot) % n;
            if(A[realmid] == target) return realmid;
            if(A[realmid] < target) lo = mid+1;
            else hi = mid - 1;
        }
        return -1; // not found
    }
};
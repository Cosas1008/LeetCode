/*
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B){
        if(A.size() < B.size()) return findMedianSortedArrays(B, A);
        int N1 = A.size();
        int N2 = B.size();
        // N1 > N2
        int lo = 0, hi = N2*2;
        while(lo <= hi){
            int mid2 = (lo + hi) / 2;
            int mid1 = N1 + N2 - mid2;

            double L1 = mid1==0? INT_MIN : A[(mid1-1)/2];
            double L2 = mid2==0? INT_MIN : B[(mid2-1)/2];
            double R1 = mid1==N1*2? INT_MAX : A[(mid1)/2];
            double R2 = mid2==N2*2? INT_MAX : B[(mid2)/2];
            if(L1 > R2) lo = mid2 + 1;
            else if(L2 > R1) hi = mid2 - 1;
            else return (max(L1,L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};
/*
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
*/
class Solution {
public:
    int divide(int A, int B) {
        if(A == INT_MIN && B == -1) return INT_MAX;
        int a = abs(A), b = abs(B), res = 0, x = 0;
        for (int x = 31; x >= 0; x--)
            if ((signed)((unsigned)a >> x) - b >= 0)
                res += 1 << x, a -= b << x;
        return (A > 0) == (B > 0)? res : -res;
    }
};
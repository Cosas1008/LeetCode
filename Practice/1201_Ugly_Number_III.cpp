/*
An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
*/
class Solution {
public:
    // Binary Search
    int nthUglyNumber(int n, int a, int b, int c){
        if(n == 1) return 1;
        int lo = 1, hi = INT_MAX;
        long ab = (long) a * b / gcd((long)a,(long)b);
        long bc = (long) b * c / gcd((long)b,(long)c);
        long ac = (long) a * c / gcd((long)a,(long)c);
        long abc = (long) a * bc / gcd((long)a, bc);
        while(lo < hi){
            int mi = lo + (hi-lo)/2;
            int cnt = mi / a + mi / b + mi / c - mi / ab - mi / bc - mi / ac + mi / abc;
            if(cnt < n)
                lo = mi + 1;
            else
                hi = mi;
        }
        return lo;
    }
    // Wrong with Overflow, cannot solve with II
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<int> res(1,1);
        int i, j, k;
        i = j = k = 0;
        while(res.size() < n){
            res.push_back(min({res[i]*a, res[j]*b, res[k]*c}));
            if(res.back() == res[i]*a) ++i;
            if(res.back() == res[j]*b) ++j;
            if(res.back() == res[k]*c) ++k;
        }
        return res.back();
    }
};
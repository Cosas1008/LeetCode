/*
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN){
            if(divisor==-1)
                return INT_MAX;
            else if(divisor==1)
                return dividend;
            else
                return ((divisor&1)==1)?  
                    divide(dividend+1,divisor) : divide(dividend>>1,divisor>>1);
        } 
        if(divisor==INT_MIN) return 0;
        
        if (dividend == 1 << 31 && divisor == -1) return (1 << 31) - 1;
        int a = abs(dividend), b = abs(divisor), ret = 0;
        for(int x = 31; x >= 0; x--){
            if((signed)((unsigned)a >> x) - b >= 0){
                a   -= b << x;
                ret += 1 << x;
            }
        }
        return (dividend > 0) == (divisor > 0)? ret : -ret;
    }
};
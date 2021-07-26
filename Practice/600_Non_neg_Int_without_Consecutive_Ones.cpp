class Solution {
public:
    int findIntegers(int num){
        int ans = 0, k = 30, pre_bit = 0;
        int fib[32];
        fib[0] = 1;
        fib[1] = 2;
        for(int i = 2; i < 32; ++i)
            fib[i] = fib[i-1] + fib[i-2];
        while(k >= 0){
            if(num &(1<<k)){
                ans += fib[k];
                if(pre_bit) return ans;
                pre_bit = 1;
            }else{
                pre_bit = 0;
            }
            k--;
        }
        return ans + 1;
    }
};
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int arr[2] = {0};
        long mod = 1E9+7;
        int zero = 0;
        for(int i = binary.length() - 1; i >= 0; i--){
            int val = binary[i] - '0';
            arr[val] = 1 + arr[0] + arr[1];
            arr[val] %= mod;
            if(val == 0)
                zero = 1;
        }
        return arr[1] + zero;
    }
};
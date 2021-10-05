/*
Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.

Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
*/
class Solution {
    // Sliding windows
    int minFlips(string s){
        int res = INT_MAX, s0 = 0, s1 = 0, sz = s.size();
        for(int i = 0; i < 2 * sz; i++){
            s0 += (s[i%sz] ^ i) & 1;
            s1 += (s[i%sz] ^ (i+1)) & 1;
            if(i >= sz-1){
                if(i >= sz){
                    s0 -= (s[i-sz] ^ (i-sz)) & 1;
                    s1 -= (s[i-sz] ^ (i-sz + 1)) & 1;
                }
                res = min(res, min(s0, s1));
            }
        }
        return res;
    }
};
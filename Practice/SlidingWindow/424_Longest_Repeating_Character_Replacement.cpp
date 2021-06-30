/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.
Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

// This solution is sooo creative, great to learn
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, maxf = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < s.length(); ++i) {
            maxf = max(maxf, ++count[s[i]]); // count of frequece char
            if (res - maxf < k){
                res++;
            }else{
                // cout << " i " << i << " res " << res << " s " << s[i - res] << endl;
                count[s[i - res]]--;
            }
        }
        return res;
    }
};

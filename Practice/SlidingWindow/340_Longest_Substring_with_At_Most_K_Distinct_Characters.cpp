/*
Example
Example 1:

Input: S = "eceba" and k = 3
Output: 4
Explanation: T = "eceb"
Example 2:

Input: S = "WORLD" and k = 4
Output: 4
Explanation: T = "WORL" or "ORLD"
*/

// Magic Sliding Window
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        return helper(s, k) - helper(s, k - 1);
    }
    int helper(string& s, int k){
       int head = 0, res = 0;
       unordered_map<int, int> m;
       for(int j = 0; j < s.size(); j++){
           if(!m[s[j]]++) k--;
           while( k < 0){
               if(!--m[s[i]]) k++;
               i--;
           }
            res += j - i + 1;
       }
       return res;
    }
}
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
            while (m.size() > k) {
                if (--m[s[left]] == 0) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};
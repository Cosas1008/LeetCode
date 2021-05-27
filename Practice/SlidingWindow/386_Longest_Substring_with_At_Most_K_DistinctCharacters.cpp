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

class Solution {
public:
   int lengthOfLongestSubstringKDistinct(string s, int k) {
       int ans = 0;
       int x   = 0;
       unordered_map<int, int> m;
       int n = s.size();
       for(int j = 0, i = 0; j < n; j++){
           m[s[j]]++;
           if(m[s[j]] == 1){ // first char in substr
               x++;
           }
           while(x > k && i <= j){
               if(--m[s[i]] == 0){
                   x--;
               }
               i++
           }
           ans = max(ans, x);
        }
        return ans;
    }
}

// Magic way
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
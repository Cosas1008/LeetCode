/*
Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
*/
class Solution {
public:
    int myAtoi(string s) {
      int i = 0, neg = 1;
      long long ans = 0;
      while(s[i] == ' ') i++;
      if(s[i] == '-') neg = -1, i++;
      else if(s[i] == '+') neg = 1, i++;
      while(s[i] >= '0' && s[i] <= '9'){
        ans = ans * 10 + s[i++] - '0';
        if(ans > INT_MAX) break;
      }
      return ans > INT_MAX? neg==-1? INT_MIN : INT_MAX : neg * ans;
    }
};
// Complex
class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        int start = 0;
        bool negative = false;

        // remove space
        while(start < len){
            if(s[start] == ' '){
                start++;
            }
            else break;
        }
        if(s[start] == '+') start++;
        else if(s[start] == '-') negative = true, start++;
        long long ans = 0;
        for(int i = start; i < len; i++){
            if(isdigit(s[i]))
                ans = ans * 10 + (s[i] - '0');
            else break;
            if(ans > INT_MAX) break;
        }
        if(negative) ans = ans * -1;
        if(ans < INT_MIN) return INT_MIN;
        else if(ans > INT_MAX) return INT_MAX;
        return ans;
    }
};
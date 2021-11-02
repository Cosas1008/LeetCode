/*
You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.
A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

Example 1:

Input: s = "QWER"
Output: 0
Explanation: s is already balanced.

Hint: we want to know the count outside the window.
*/
class Solution {
public:
    int balancedString(string s){
        unordered_map<int, int> count;
        int n = s.length(), res = n, i = 0, k = n / 4;
        for(int j = 0; j < n; ++j)
            count[s[j]]++;
        for(int j = 0; j < n; ++j){
            count[s[j]]--;
            while(i < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k){
                res = min(res, j - i + 1);
                count[s[i++]]++;
            }
        }
        return res;
    }
};
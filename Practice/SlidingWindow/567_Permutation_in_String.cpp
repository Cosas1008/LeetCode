/*
Given two strings s1 and s2, return true if s2 contains the permutation of s1.
In other words, one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

// I like this solution
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> dict(26, 0), cur(26, 0);
        for(char c : s1){
            dict[c-'a']++;
        }
        int left = 0, tz = s1.length();
        for(int i = 0; i < s2.length(); i++){
            cur[s2[i] - 'a']++; // front
		    if(i >= s1.size()) cur[s2[i - s1.size()] - 'a']--; // remove front
		    if(dict == cur) return true;
        }
        return false;
    }
};
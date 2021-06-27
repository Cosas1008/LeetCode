/*
Given the strings s1 and s2 of size n and the string evil, return the number of good strings.
A good string has size n, it is alphabetically greater than or equal to s1, 
it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. 
Since the answer can be a huge number, return this modulo 109 + 7.

Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
Output: 51 
Explanation: There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". 
Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" 
and finally there is one good string starting with 'd': "da".

Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
Output: 0 
Explanation: All strings greater than or equal to s1 and smaller than or equal to s2 start with the prefix "leet", therefore, there is not any good string.

Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
Output: 2
*/
class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        int cnt = 0;
        s1 +++ until s2 
        skip string contain evil char
        return cnt;
    }
};
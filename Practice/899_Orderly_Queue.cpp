/*
You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..
Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

Input: s = "cba", k = 1
Output: "acb"
Explanation: 
In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".
*/
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1){
            string ans = s;
            for(int i = 0; i < s.length(); i++)
                ans = min(ans, s.substr(i) + s.substr(0,i));
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
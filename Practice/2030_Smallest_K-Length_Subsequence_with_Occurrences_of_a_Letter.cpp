/*
Return the lexicographically smallest subsequence of s of length k that has the letter letter
appear at least repetition times. The test cases are generated so that the letter appears in s
at least repetition times.

Input: s = "leetcode", k = 4, letter = "e", repetition = 2
Output: "ecde"
Explanation: "ecde" is the lexicographically smallest subsequence of length 4 that has the letter "e" appear at least 2 times.
*/
class Solution {
public:
    // Hint : build answer character by character
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        // say we are adding jth character to the answer string
        int n = s.length();
        vector<deque<int>> ind(26);
        for(int i = 0; i < n; ++i)
            ind[s[i]-'a'].push_back(i);
        int x = repetition, lastInd = -1;
        string ans = "";
        for(int j = 0; j < k; ++j){
            for(int ch = 0; ch < 26; ++ch){
                auto & dq = ind[ch];
                while(dq.size() && dq.front() < lastInd) dq.pop_front(); // remove invalid indexes
                if(!dq.size()) continue;

                // check if current index satisfies the condition
                auto index = dq.front();
                // 1. Length of remaininig suffix + answer string length >= k =>. n-i+j-1 >= k
                // 2. The count of letter in remaining suffix of input string ( = s[i ... n-1] ) >= x.
                // 3. Requirement + current length is not exceeding the K => x+j+1 <= k
                if(ans.length() + n - index >= k && cnt[index] >= x && (x - (ch+'a'==letter) + j + 1 <= k)){
                    ans += ch + 'a';
                    if(ch+'a' == letter ) x--;
                    lastInd = index;
                    dq.pop_front();
                    break;
                }
            }
        }
        return ans;
    }
};
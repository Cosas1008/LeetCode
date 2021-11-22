/*
Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
*/
/*
Hint: Think about string "XAXAXXAX" and focus on making the second "A" a unique character.
We can take "XA(XAXX)AX" and between "()" is our substring.
We can see here, to make the second "A" counted as a uniq character, we need to:

insert "(" somewhere between the first and second A
insert ")" somewhere between the second and third A
Total : 2 * 3 = 6 ways to make the second A as unique string
*/
class Solution {
public:
    int uniqueLetterString(string s) {
        // index[26][2] record last two occurrence index for every upper characters
        int index[26][2], res = 0, N = s.length(), mod = pow(10, 9) + 7;
        memset(index, -1, sizeof(int) * 52); // total 52 entries
        for(int i = 0; i < N; ++i){
            int c = s[i] - 'A';
            res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod);
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        // To think about last loop, this is the last sum from left to each last appeared character
        for(int c = 0; c < 26; ++c)
            res = (res + (N - index[c][1]) * (index[c][1] - index[c][0]) % mod ) % mod;
        return res;
    }
};
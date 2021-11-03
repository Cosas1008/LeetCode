/*
Input: s = "7+3*1*2", answers = [20,13,42]
Output: 7
Explanation: As illustrated above, the correct answer of the expression is 13, therefore one student is rewarded 5 points: [20,13,42]
A student might have applied the operators in this wrong order: ((7+3)*1)*2 = 20. Therefore one student is rewarded 2 points: [20,13,42]
The points for the students are: [2,5,0]. The sum of the points is 2+5+0=7.
*/
class Solution {
public:
    unordered_set<int> memo[32][32];
    int scoreOfStudents(string s, vector<int>& answers) {
        int correct = 0;
        // calculate correct answer first
        for(int i = 1, j = 0; i <= s.length(); i+=2){
            if(i == s.length() || s[i] == '+'){
                int mul = 1;
                for(; j < i; j += 2)
                    mul *= s[j] - '0';
                correct += mul;
            }
        }
        dfs(s, 0, s.length());
        return accumulate(begin(answers), end(answers), 0, [&](int sum, int ans){
            return sum + (ans == correct ? 5 :  memo[0][s.size()].count(ans) ? 2 : 0);
        });
    }
    void dfs(string& str, int s, int e){
        if(memo[s][e].empty()){
            if(e - s == 1)
                memo[s][e].insert(str[s] - '0');
            for(int i = s+1; i < e; i += 2){
                dfs(str, s  , i);
                dfs(str, i+1, e);
                for(int n1 : memo[s][i]){
                    for(int n2 : memo[i+1][e]){
                        int n = str[i] == '*'? n1 * n2 : n1 + n2;
                        if(n <= 1000)
                            memo[s][e].insert(n);
                    }
                }
            }
        }
    }
};
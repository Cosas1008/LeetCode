/*
flip two consecutive '++' to '--'
return true if you can win the game, false otherwise
*/
class Solution {
 public:
  bool canWin(string s) {
    if(memo.count(s))
        return memo[s];
    for(int i = 0; i < s.length(); ++i)
        if(s[i] == '+' && s[i+1] == '+' &&
            !canWin(s.substr(0, i) + "--" + s.substr(i+1)))
            return memo[s] = true;
    return memo[s] = false;
  }
private:
  unordered_map<string, bool> memo;
};
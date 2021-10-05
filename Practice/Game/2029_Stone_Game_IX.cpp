/*
Alice and Bob take turns, with Alice starting first. 
On each turn, the player may remove any stone from stones. 
The player who removes a stone loses if the sum of the values of all removed stones is divisible by 3. 
Bob will win automatically if there are no remaining stones (even if it is Alice's turn).

Assuming both players play optimally, return true if Alice wins and false if Bob wins.
*/

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};
        for(int a : stones)
            cnt[a% 3]++;
        // If cnt[1] == 0, Alice needs to start with mod3 = 2,
        // If cnt[2] == 0, Alice needs to start with mod3 = 1.
        if(min(cnt[1], cnt[2]) == 0)
            return max(cnt[1], cnt[2]) > 2 && cnt[0] % 2 > 0;
        return abs(cnt[1] - cnt[2]) > 2 || cnt[0] % 2 == 0;
    }
};
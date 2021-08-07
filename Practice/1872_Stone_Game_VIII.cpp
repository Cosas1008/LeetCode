/*
Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, while the number of stones is more than one, they will do the following:

Choose an integer x > 1, and remove the leftmost x stones from the row.
Add the sum of the removed stones' values to the player's score.
Place a new stone, whose value is equal to that sum, on the left side of the row.
The game stops when only one stone is left in the row.
*/
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for(int i = 1; i < n; i++){
            stones[i] += stones[i-1];
        }
        int ans = stones.back();
        for(int i = n-2; i >= 0; i--){
            ans = max(ans, stones[i] - ans);
        }
        return ans;
    }
};
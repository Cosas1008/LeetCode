/*
In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
What if we change the game so that players cannot re-use integers?
*/
// ref https://leetcode.com/problems/can-i-win/discuss/230432/C%2B%2B-12-ms-98-solution-with-detailed-explanation
class Solution {
public:
    bool canIWin(int M, int D) {
        if(M >= D) return true; // wins if desired below max
        int tmp = M*(M+1)/2;
        if(tmp < D) return false; // No win if it is unreachable
        if(tmp == D && m%2 == 1) return true; // Win if desired = max possible sum, only if maxChoose is odd
        total = D; _max = M;
        return !helper(0,0);
    }
    bool helper(int cur, int state){
        if(cur >= total){
            visited.set(state);
            cache.set(state);
            return true;
        }

        for(int i = 1; i <= _max; ++i){
            if((state & (1<<i)) == 0) {
                int newState = state | (1<<i);
                if((visited[newState] && cache[newState]) || (!visited[newState] && helper(cur+1, newState))) {
                    visited.set(state);
                    return false;
                }
            }
        }
        visited.set(state);
        cache.set(state);
        return true;
    }
private:
    bitset< 1<<21 > cache;
    bitset< 1<<21 > visited;
    int total, _max;
};
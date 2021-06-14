/*
Input: machines = [1,0,5]
Output: 3
Explanation:
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3
3rd move:    2     1 <-- 3    =>    2     2     2

Input: machines = [0,2,0]
Output: -1
Explanation:
It's impossible to make all three washing machines have the same number of dresses.
*/
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if(sum % n != 0) return -1;
        int target = sum / n;
        int step = 0;
        int toRight = 0;// reference 
        for(int m : machines){
            toRight += m - target;
            step = max(step, max(abs(toRight), m - target)); // geneous
        }
        return step;
    }
};
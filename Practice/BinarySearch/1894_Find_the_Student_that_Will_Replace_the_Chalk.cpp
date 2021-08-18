/*
You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem.
However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.

Return the index of the student that will replace the chalk.
Input: chalk = [5,1,5], k = 22
Output: 0
Explanation: The students go in turns as follows:
- Student number 0 uses 5 chalk, so k = 17.
- Student number 1 uses 1 chalk, so k = 16.
- Student number 2 uses 5 chalk, so k = 11.
- Student number 0 uses 5 chalk, so k = 6.
- Student number 1 uses 1 chalk, so k = 5.
- Student number 2 uses 5 chalk, so k = 0.
Student number 0 does not have enough chalk, so they will have to replace it.
*/
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long> accumulate(chalk.size());
        long long sum = 0;
        for(int i = 0; i < chalk.size(); i++){
            sum += chalk[i];
            accumulate[i] = sum;
        }
        k %= sum;
        int left, right;
        left = 0;
        right = chalk.size()-1;
        while(left < right){
            int mid = (right - left) / 2 + left;
            if(accumulate[mid] > k){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
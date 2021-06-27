/*
You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

*/
class Solution {
public:
    int candy(vector<int>& ratings) { 
        // greedy
        int n = ratings.size();
        vector<int> candy(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candy[i] = candy[i-1]+1;
            }
        }
        for(int i = n - 1; i > 0; i--){
            if(ratings[i-1] > ratings[i]){
                candy[i-1] = max(candy[i] + 1, candy[i-1]);
            }
        }
        return accumulate(candy.begin(), candy.end(), 0);
    }
};
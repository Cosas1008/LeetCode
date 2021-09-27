/*
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int minPrice = INT_MAX;
        for(int price : prices){
            minPrice = min(price, minPrice);
            ret = max(ret,price - minPrice);
        }
        return ret
    }
};
// 2016. Maximum Difference Between Increasing Elements
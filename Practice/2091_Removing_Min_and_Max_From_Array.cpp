/*
Input: nums = [2,10,7,5,4,1,8,6]
Output: 5
Explanation: 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.
*/
class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int N = A.size();
        if(N <= 2) return N;
        int a = min_element(A.begin(), A.end()) - A.begin();
        int b = max_element(A.begin(), A.end()) - A.begin();
        if(a > b) swap(a, b); // a is closer to left
        return min({a + 1 + N - b, b + 1, N - a}); // case1 remove both, case2 remove from left, case3 remove from right
    }
};
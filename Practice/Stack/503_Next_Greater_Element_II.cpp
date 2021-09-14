/*
The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. 
If it doesn't exist, return -1 for this number.
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n, -1);
        vector<int> stack;
        for(int i = 0 ; i < 2*n; i++){
            while(stack.size() && A[stack.back()] < A[i % n]){
                ans[stack.back()] = A[i%n];
                stack.pop_back();
            }
            stack.push_back(i % n);
        }
        return ans;
    }
};
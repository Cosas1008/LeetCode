/*
Given a pizza with 3n slices (e.g. 9, 12,...), repeatedly pick a slice (save the size of this slice). 
When you do this, the slice on the left goes to someone on the left, and the slice on the right goes to someone on the right.
Repeat this process until no slices are left. How can you write a program to find a list of slices that has the maximum sum?
*/

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size() / 3;
        vector<int> arr1(slices.begin() + 1, slices.end());
        vector<int> arr2(slices.begin(), slices.end() - 1);
        return max(linear(arr1, n) , linear(arr2, n));
    }
    int linear(vector<int>& slice, int n)
    {
        vector<vector<int>> eat(slice.size() + 2, vector<int>(n+1, INT_MIN));
        int res = INT_MIN;
        for(int i = 0; i < eat.size(); i++) eat[i][0] = 0;
        for(int i = 2; i < eat.size(); i++){
            for(int j = 1; j < n+1; j++){
                eat[i][j] = max(eat[i-1][j], eat[i-2][j-1] + slice[i-2]);
            }
            res = max(eat[i][n], res);
        }
        return res;
    }
};
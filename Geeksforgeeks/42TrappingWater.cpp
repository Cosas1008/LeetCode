/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.
Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
#include<vector>
#include<algorithm>

class Solution {
public:
    // brute-force : find each height can contain how much water
    // Complexity: O^2
    // Space : 1
    int trap(vector<int>& height) {
        int answer = 0;
        int size = height.size();
        for(int i = 1; i < size - 1; i++)
        {
            int leftmost = 0;
            int rightmost = 0;
            for(int k = i; k >= 0; k--)
            {
                leftmost = max(leftmost, height[k]);
            }
            for(int j = i; j < size; j++)
            {
                rightmost = max(rightmost, height[j]);
            }
            answer += min(rightmost,leftmost) - height[i];
        }
        return answer;
    }
};
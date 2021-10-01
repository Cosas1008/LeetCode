/*
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area( from 5 to 6 ), which has an area = 10 units.
*/
class Solution {
public:
    // 2-pass
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, n = heights.size();
        vector<int> left(n), right(n);
        left[0]    = -1;
        right[n-1] = n;
        for(int i = 1; i < n; i++){
            int p = i - 1;
            while(p >= 0 && heights[p] >= heights[i])
                p = left[p];
            left[i] = p;
        }
        for(int i = n-2; i >= 0; i--){
            int p = i+1;
            while(p < n && heights[p] >= heights[i])
                p = right[p];
            right[i] = p;
        }
        for(int i = 0; i < n; i++)
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
        return maxArea;
    }
    // Using Stack 1-pass
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        vector<int> index;
        heights.push_back(0); // key here**
        for(int i = 0; i < heights.size(); i++){
            while(index.size() && heights[index.back()] >= heights[i]){
                int h = heights[index.back()];
                index.pop_back();
                int first = index.size()>0? index.back() : -1;
                ret = max(ret, h * (i - first - 1));
            }
            index.push_back(i);
        }
        return ret;
    }
};
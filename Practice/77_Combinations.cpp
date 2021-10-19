/*
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
n = 3 k = 2
[0,0]
[1,1]
[1,2] -> add
[1,3] -> add
[1,4] -> over, moveing index to left and increase
[2,4] -> moving index to right and copy
[2,2]
[2,3] -> add ..

*/
class Solution {
public:
    // Excellent solution
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        int i = 0;
        vector<int> p(k, 0);
        while(i >= 0){
            p[i]++;
            if(p[i] > n) --i;
            else if(i == k - 1) ans.push_back(p);
            else{
                ++i;
                p[i] = p[i-1]; // Move index to the right and set the element at that index equal to the previous
            }
        }
        return ans;
    }
};
/*
Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

Input:
[10,2]
[3,30,34,5,9]
[0,0]
Output:
"210"
"9534330"
"0"

*/

class Solution {
public:
    static bool mycomp(const int& lh, const int& rh){
        string lr = to_string(lh) + to_string(rh);
        string rl = to_string(rh) + to_string(lh);
        return lr.compare(rl) > 0 ? 1 : 0;
    };
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), mycomp);
        string ans = "";
        for(int& num : nums){
            ans += to_string(num);
        }
        while(ans[0] == '0' && ans.length() > 1){
            ans.erase(0,1);
        }
        return ans;
    }
};
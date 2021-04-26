// Wrong, TLE
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        vector<int> revnum(n);
        for(int i = 0; i < n; i++){
            revnum[i] = rev(nums[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + revnum[j] = nums[j] + revnum[i]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int rev(int num){
        string str = to_string(num);
        for(int i = 0; i < str.size() / 2; i++){
            swap(str[i], str[str.size() - 1 - i]);
        }
        return std::stoi(str);
    }
};

// Reference on Leetcode
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        int res = 0;
        unordered_map<int,int> count;
        for(int& num : nums){
            res = (res + count[num - rev(num)]++) % mod;
        }
        return res;
    }
    int rev(int num){
        int b = 0;
        while (a > 0) {
            b = b * 10 + (a % 10);
            a /= 10;
        }
        return b;
    }
};
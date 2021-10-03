class Solution {
public:
    // I originally thought this question should be solved by DP, actually it's not!
    int numOfPairs(vector<string>& A, string target) {
        int sz = target.size();
        vector<int> dp(sz+1, 0);
        dp[0] = 1;
        for(string a : A){
            for(int i = 0; i <= sz-len; i++){
                
            }
        }
        for(int i = 0; i <= sz; i++)
            cout << dp[i] << " ";
        cout << endl;
        return dp[sz];
    }
    // Bizzard!
    int numOfPairs(vector<string>& A, string target) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < i; ++j){
                if(nums[i] + nums[j] == target)
                    ans+=1;
                if(nums[j] + nums[i] == target)
                    ans+=1;
            }
        return ans;
    }
    // Prefix State Map
    // Time O(N)
    int numOfPairs(vector<string>& A, string s){
        unordered_map<string, int> m;
        int ans = 0;
        // for example : "7" will find "777" in case of s = "7777"
        for(string& a : A){
            if(a.size() > s.size()) continue;
            if(s.substr(0,a.size()).compare(a)==0)
                ans += m[s.substr(a.size())];
            m[a]++;
        }
        m.clear();
        reverse(begin(A), end(A));
        for(string& a : A){
            if(a.size() > s.size()) continue;
            if(s.substr(0, a.size()).compare(a)==0)
                ans += m[s.substr(a.size())];
            m[a]++;
        }
        return ans;
    }
};
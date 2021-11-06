/*
Input: target = [5,1,3], arr = [9,4,2,3,4]
Output: 2
Explanation: You can add 5 and 1 in such a way that makes arr = [5,9,4,1,2,3,4], then target will be a subsequence of arr.

Hint: Longest Increasing Subsequence
*/
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i = 0; i < target.size(); ++i)
            m[target[i]] = i;

        vector<int> index; // Store index of this element ref to target
        
        for(int& a : arr)
            if(m.count(a)){
                index.push_back(m[a]);
            }
        
        vector<int> lis; // longest increasing subsequence

        for(auto a : index){
            auto it = lower_bound(lis.begin(), lis.end(), a);
            if(it == lis.end())
                lis.push_back(a);
            else
                *it = a;
        }

        return target.size() - lis.size();
    }
};
/*
You are given an integer n and an array of unique integers blacklist. 
Design an algorithm to pick a random integer in the range [0, n - 1] that is not in blacklist. 
Any integer that is in the mentioned range and not in blacklist should be equally likely returned.
*/

class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        sort(blacklist.begin(), blacklist.end());
        for(int i = 0; i < blacklist.size(); i++)
            prefix.push_back(blacklist[i] - i);
        prefix.push_back(n - blacklist.size());
        dis = std::uniform_int_distribution<>(0, n - prefix.size());
    }
    
    int pick() {
        int idx = dis(gen);
        return idx + (upper_bound(prefix.begin(), prefix.end(), idx) - prefix.begin());
    }
private:
    vector<int> prefix;
    mt19937 gen;
    uniform_int_distribution<> dis;
};
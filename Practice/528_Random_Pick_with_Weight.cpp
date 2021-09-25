/*
We need to call the function pickIndex() which randomly returns an integer in the range [0, w.length - 1]. 
pickIndex() should return the integer proportional to its weight in the w array.
*/
class Solution {
public:
    vector<int> weight;
    Solution(vector<int>& w) {
        weight.push_back(w[0]);
        for(int i = 1; i < w.size(); ++i)
            weight.push_back(weight.back() + w[i]);
    }
    
    int pickIndex() {
        int x = weight.back();
        int idx = rand() % x;
        auto it = upper_bound(weight.begin(), weight.end(), idx);
        return it - weight.begin();
    }
};
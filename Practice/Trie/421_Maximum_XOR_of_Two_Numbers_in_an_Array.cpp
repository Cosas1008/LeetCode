/*
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
*/
class Solution {
public:
    struct Trie{
        Trie* t[2];
        Trie(){
            t[0] = t[1] = NULL;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        root = new Trie;
        for(int& num : nums){
            insert(root, num);
        }
        int ans = 0;
        for(int& num : nums){
            int res = 0;
            findMax(root, num, res);
            ans = max(ans, res);
        }
        return ans;
    }
    void findMax(Trie* rt, int num, int& res, int i = 31){
        if(!rt) return;
        if(i < 0) return;
        int num_b = (num >> i ) & 1;
        if(num_b == 1){
            if(rt->t[0]){
                res |= (1<<i);
                findMax(rt->t[0], num, res, i-1);
            }else{
                findMax(rt->t[1], num, res, i-1);
            }
        }else{ // num_b == 0
            if(rt->t[1]){
                res |= (1<<i);
                findMax(rt->t[1], num, res, i-1);
            }else{
                findMax(rt->t[0], num, res, i-1);
            }
        }
    }
    void insert(Trie* root, int num, int i = 31){
        if(i >= 0){
            int b = (num >> i) & 1;
            if(!root->t[b]) root->t[b] = new Trie();
            insert(root->t[b], num, i-1);
        }
    }
private:
    struct Trie* root;
};
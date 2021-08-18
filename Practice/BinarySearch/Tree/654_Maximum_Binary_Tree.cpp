/*
You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution {
public:
    // Standard Cartesian Tree OP
    TreeNode* constructMaximumBinaryTree(vector<int>& A) {
        map<int, TreeNode*> q;
        for(int a : A){
            auto it = q.insert({a, new TreeNode(a)}).first;
            if(it != q.begin()){
                it->second->left = next(it, -1)->second;
                q.erase(q.begin(), it);
            }
            if(next(it, 1) != q.end()) next(it, 1)->second->right = it->second;
        }
        return q.rbegin()->second;
    }

    // Optimize with stack instead of map
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> s { new TreeNode(nums[0]) };
        for (int i = 1; i < nums.size(); ++i) {
            TreeNode* cur = new TreeNode(nums[i]);
            auto it = upper_bound(s.rbegin(), s.rend(), cur, [](const TreeNode* a, const TreeNode* b) { return a->val < b->val; });
            if (it != s.rend()) (*it)->right = cur;
            if (it != s.rbegin()) cur->left = *next(it, -1);
            s.resize(distance(it, s.rend()));
            s.push_back(cur);
        }
        return s.front();
    }

    // Fantastic One!
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> s;
        for(int num : nums){
            TreeNode* cur = new TreeNode(num);
            while(!s.empty() && s.back()->val < num){ // small one to left-hand side
                cur->left = s.back();
                s.pop_back();
            }
            if(!s.empty())
                s.back()->right = cur;
            s.push_back(cur);
        }
        return s.front();
    }
};
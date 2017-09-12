/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        walkTree(root);
        int length = numbers.size();
        if(length <= 1){
            return -1;
        }
        vector<int> values(numbers.begin(),numbers.end());
        sort(values.begin(),values.end());
        return values[1];
    }
private:
    set<int> numbers;
    void walkTree(TreeNode* root){
        numbers.insert(root->val);
        if(root->left){walkTree(root->left);};
        if(root->right){walkTree(root->right);};
    }
};


//queue solution, bfs

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        queue<TreeNode *> q;
        q.push(root);
        while(! q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
            if(p){
                s.insert(p->val);
            }
            if(p->left){q.push(p->left);};
            if(p->right){q.push(p->right);};
        }
        s.erase(s.begin());
        return s.empty()? -1: *s.begin();

    }
};
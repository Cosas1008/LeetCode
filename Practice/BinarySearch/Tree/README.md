# Traversal

1. Preorder   
2. Inorder   
3. Postorder   
### Inorder Traversal

* 98 Validate BST
* 230 Kth Smallest Element in a BST

# 105 & 106 Pre/Post + Inorder to build Binary Tree

Interesting problem..
### Postorder Traversal  

* 1120 Maximum Average Subtree

### 654 Maximum Binary Tree
![Cartesian Tree](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d5/Cartesian_tree.svg/480px-Cartesian_tree.svg.png)


# Problems
- [x] 95   Unique BST II (TL;DR)
- [x] 230  Kth Smallest Element in a BST
- [x] 654  Maximum Binary Tree ( *Cartesian tree* )
- [x] 1150 Two Sum BSTs
- [x] 1339 Max Product of Splitted Binary Tree

* Follow up for 230
Assume we have to modify and query K-th smallest element in a BST frequently, how to optimize   

// Follow up
```cpp
class Solution {
public:
    struct MyTreeNode {
        int val;
        int count;
        MyTreeNode *left;
        MyTreeNode *right;
        MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
    };
    
    MyTreeNode* build(TreeNode* root) {
        if (!root) return NULL;
        MyTreeNode *node = new MyTreeNode(root->val);
        node->left = build(root->left);
        node->right = build(root->right);
        if (node->left) node->count += node->left->count;
        if (node->right) node->count += node->right->count;
        return node;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        MyTreeNode *node = build(root);
        return helper(node, k);
    }
    
    int helper(MyTreeNode* node, int k) {
        if (node->left) {
            int cnt = node->left->count;
            if (k <= cnt) {
                return helper(node->left, k);
            } else if (k > cnt + 1) {
                return helper(node->right, k - 1 - cnt);
            }
            return node->val;
        } else {
            if (k == 1) return node->val;
            return helper(node->right, k - 1);
        }
    }
};
```
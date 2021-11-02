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

* 563  Binary Tree Tilt
* 1120 Maximum Average Subtree

### 654 Maximum Binary Tree
![Cartesian Tree](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d5/Cartesian_tree.svg/480px-Cartesian_tree.svg.png)


# Problems
- [x] 95   Unique BST II (TL;DR)
- [x] 98   Validate BST
- [x] 103  BT Zigzag Level Order Traversal
- [x] 113  Path Sum II
- [x] 124  Binary Tree Maximum Path Sum (DP)
- [x] 156  Binary Tree Upside-down
- [x] 230  Kth Smallest Element in a BST ( Recommanded )
- [x] 297  Serialize and Deserialize BST ( same as 449 )
- [x] 333  Largest BST Subtree ( follow up from 98)
- [x] 437  Path Sum III
- [x] 543  Diameter of BT
- [x] 563  BT Tilt
- [x] 652  Find Duplicate Subtrees ( use serialize technique )
- [x] 654  Maximum Binary Tree ( *Cartesian tree* )
- [x] 655  Print Binary Tree
- [x] 671  Second Min Node in a BT ( DFS or BFS best practice )
- [x] 783  Min Distance Between BST Nodes ( Inorder Traversal, easy, same as  530)
- [x] 968  Binary Tree Cameras
- [x] 979  Distribute Coins in Binary Tree
- [x] 1008 Construct BST from Preorder Traversal
- [x] 1098 Path Sum IV
- [x] 1120 Max Average Subtree ( DFS )
- [x] 1150 Two Sum BSTs
- [x] 1161 Max Level Sum of a Binary Tree
- [x] 1339 Max Product of Splitted Binary Tree
- [x] 1361 Validate Binary Tree Node ( personally, it should be hard )
- [x] 1372 Longeset ZigZag Path in a BT
- [ ] 1457 Pseudo-Palindromic Paths in a Binary Tree


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
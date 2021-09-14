/*
We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.
*/

// DP solution
#define INF 9999999
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        vector<int> res = solve(root);
        return min(res[1], res[2]);
    }
private:
    vector<int> solve(TreeNode* root){
        if(!root) return {0,0,INF};
        vector<int> L = solve(root->left);
        vector<int> R = solve(root->right);
// [State 0] Strict subtree: All the nodes below this node are covered, but not this node.
// [State 1] Normal subtree: All the nodes below and including this node are covered, but there is no camera here.
// [State 2] Placed camera: All the nodes below and including this node are covered, and there is a camera here (which may cover nodes above this node).
        int dp0 = L[1] + R[1];
        int dp1 = min(L[2] + min(R[1], R[2]), R[2] + min(L[1], L[2]));
        int dp2 = 1 + *min_element(L.begin(), L.end()) + *min_element(R.begin(), R.end());
        return {dp0, dp1, dp2};
    }
};

// Greedy (TBD)
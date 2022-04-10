/*
Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of
 only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
*/
class Solution {
public:
    // 1. Build directions for both start and destination from the root.
    // Say we get "LLRRL" and "LRR".
    // 2. Remove common prefix path.
    // We remove "L", and now start direction is "LRRL", and destination - "RR"
    // 3. Replace all steps in the start direction to "U" and add destination direction.
    // The result is "UUUU" + "RR".
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s_p, d_p;
        find(root, startValue, s_p);
        find(root, destValue, d_p);
        while(s_p.size() && d_p.size() && s_p.back() == d_p.back()){
            s_p.pop_back();
            d_p.pop_back();
        }
        return string(s_p.size(), 'U') + string(rbegin(d_p), rend(d_p));
    }
    bool find(TreeNode* n, int val, string& path){
        if(n->val == val) return true;
        if(n->left && find(n->left, val, path))
            path.push_back('L');
        else if(n->right && find(n->right, val, path))
            path.push_back('R');
        return !path.empty();
    }
};
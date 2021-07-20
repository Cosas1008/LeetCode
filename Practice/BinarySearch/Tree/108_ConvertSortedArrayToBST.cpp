// Recurssive call
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0)
        return NULL;
    if(nums.size() == 1)
        return new TreeNode(nums[0]);
    int mid = nums.size() /2;
    vector<int> leftArray(nums.begin(), nums.begin() + mid);
    vector<int> rightArray(nums.begin() + mid + 1, nums.end());
    TreeNode* tNode = new TreeNode(nums[mid]);
    tNode->left = sortedArrayToBST(leftArray);
    tNode->right = sortedArrayToBST(rightArray);
    return tNode;
}
// Op 2
TreeNode* sortedArrayToBST(vector<int>& nums){
    int n = nums.size();
    if(n == 0) return nullptr;
    return a2b(nums, 0, n-1);
}
TreeNode* a2b(vector<int>& v, int start, int end){
    if(end < start){
        return NULL;
    }
    int mid = start + (end - start) / 2;
    TreeNode* node = new TreeNode(v[mid]);
    node->left = a2b(v, start, mid - 1);
    node->right = a2b(v, mid+1, end);
    return node;
}


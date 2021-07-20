/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, NULL);
    }
private:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail)
    {
        TreeNode* tNode;
        if(head == tail)
            return nullptr;
        if(head->next == tail){
            tNode = new TreeNode(head->val);
            return tNode;
        }
        ListNode* mid, *tmp;
        mid = head; tmp = head;
        while(tmp != tail && tmp->next != tail){
            mid = mid->next;
            tmp = tmp->next->next;
        }
        tNode = new TreeNode(mid->val);
        tNode->left = sortedListToBST(head, mid);
        tNode->right = sortedListToBST(mid->next, tail);
        return tNode;
    }
};
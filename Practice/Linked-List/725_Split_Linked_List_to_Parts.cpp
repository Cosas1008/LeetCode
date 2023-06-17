//Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        vector<ListNode*> ans(k, nullptr);
        ListNode* node = head, *prev = nullptr;
        while(node){
            len++;
            node = node->next;
        }
        node = head;
        int part = len / k, remain = len % k;
        for(int i = 0; node && i < k; i++, remain--){
            ans[i] = node;
            for(int j = 0; j < part + (remain>0); ++j){
                prev  = node;
                node  = node->next;
            }
            prev->next = nullptr;
        }
        return ans;
    }
};
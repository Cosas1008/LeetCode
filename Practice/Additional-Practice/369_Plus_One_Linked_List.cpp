/*
Input: [1,2,3]
Output: [1,2,4]
*/
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if(!head) return head;
        ListNode *rev = reverse(head), *cur = rev, *pre = cur;
        int carry = 1;
        while(cur){
            pre = cur;
            int t = cur->val + carry;
            cur->val = t % 10;
            carry = t / 10;
            if(carry == 0) break;
            cur = cur->next;
        }
        if(carry) pre->next = new ListNode(1);
        return reverse(rev);
    }
    ListNode* reverse(ListNode* head){
        if(!head) return head;
        ListNode* dummy = new ListNode(-1), *cur = head;
        dummy->next = head;
        while(cur->next){
            ListNode* t = cur->next;
            cur->next = t->next;
            t->next = dummy->next;
            dummy->next = t;
        }
        return dummy->next;
    }
};
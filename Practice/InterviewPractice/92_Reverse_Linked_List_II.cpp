/*
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0), * pre = dummy, * cur;
        dummy->next = head;
        for(int i = 0; i < left-1; ++i){
            pre = pre->next;
        }
        cur = pre->next;
        for(int i = 0; i < right - left; ++i){
            ListNode* tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
        }
        return dummy->next;
    }
};
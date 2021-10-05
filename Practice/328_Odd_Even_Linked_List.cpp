/*
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head, *even = head->next, *evenhead = even;
        while(even && even->next){
            odd->next = even->next;
            odd       = odd->next;
            even->next= odd->next;
            even      = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};